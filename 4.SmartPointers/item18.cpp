#include <memory>
#include <iostream>

class Test
{
public:
    Test(int a) : _data(a) { std::cout << "Test(int a)" << std::endl; }
    ~Test() { std::cout << "~Test()" << std::endl; }

private:
    int _data;
};

class Investment
{
public:
    virtual ~Investment() {}
};

class Stock : public Investment
{
public:
    Stock(int a) { std::cout << "Stock(int a)" << std::endl; }
    ~Stock() override { std::cout << "~Stock()" << std::endl; }
};
class Bond : public Investment
{
public:
    Bond(int a, int b) { std::cout << "Bond(int a, int b)" << std::endl; }
    ~Bond() override { std::cout << "~Bond()" << std::endl; }
};
class RealEstate : public Investment
{
public:
    RealEstate(int a, int b, int c) { std::cout << "RealEstate(int a, int b, int c)" << std::endl; }
    ~RealEstate() override { std::cout << "~RealEstate()" << std::endl; }
};

template <typename... Ts>
Investment *makeInvestment_test(Ts &&...params)
{
    Investment *ptr;
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        Stock stock(std::forward<Ts>(params)...);
        ptr = &stock;
    }
    if constexpr (numArgs == 2)
    {
        Bond bond(std::forward<Ts>(params)...);
        ptr = &bond;
    }
    if constexpr (numArgs == 3)
    {

        RealEstate realEstate(std::forward<Ts>(params)...);
        ptr = &realEstate;
    }
    return ptr;
}

template <typename... Ts>
Investment *makeInvestment_test2(Ts &&...params)
{
    Investment *ptr;
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        Stock *stock = new Stock(std::forward<Ts>(params)...);
        ptr = stock;
    }
    if constexpr (numArgs == 2)
    {
        Bond *bond = new Bond(std::forward<Ts>(params)...);
        ptr = bond;
    }
    if constexpr (numArgs == 3)
    {

        RealEstate *realEstate = new RealEstate(std::forward<Ts>(params)...);
        ptr = &realEstate;
    }
    return ptr;
}

template <typename... Ts>   // 返回指向对象的std::unique_ptr，
std::unique_ptr<Investment> // 对象使用给定实参创建
makeInvestment(Ts &&...params)
{
    std::unique_ptr<Investment> uptr{nullptr};
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        uptr.reset(new Stock(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 2)
    {
        uptr.reset(new Bond(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 3)
    {
        uptr.reset(new RealEstate(std::forward<Ts>(params)...));
    }
    return uptr;
}

auto delInvmt = [](Investment *pInvestment) // 自定义删除器
{                                           // （lambda表达式）
    std::cout << "delete" << std::endl;
    delete pInvestment;
};

template <typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt)> // 更改后的返回类型
makeInvestment2(Ts &&...params)
{
    std::unique_ptr<Investment, decltype(delInvmt)> // 应返回的指针
        uptr(nullptr, delInvmt);
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        uptr.reset(new Stock(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 2)
    {
        uptr.reset(new Bond(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 3)
    {
        uptr.reset(new RealEstate(std::forward<Ts>(params)...));
    }
    return uptr;
}

template <typename... Ts>
auto makeInvestment3(Ts &&...params) // C++14
{
    auto delInvmt2 = [](Investment *pInvestment) // 现在在
    {                                            // makeInvestment里
        std::cout << "delete" << std::endl;
        delete pInvestment;
    };

    std::unique_ptr<Investment, decltype(delInvmt2)> // 应返回的指针
        uptr(nullptr, delInvmt2);
    constexpr int numArgs = sizeof...(params);
    if constexpr (numArgs == 1)
    {
        uptr.reset(new Stock(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 2)
    {
        uptr.reset(new Bond(std::forward<Ts>(params)...));
    }
    if constexpr (numArgs == 3)
    {
        uptr.reset(new RealEstate(std::forward<Ts>(params)...));
    }
    return uptr;
}

void delInvmt3(Investment *pInvestment) // 函数形式的
{                                       // 自定义删除器
    std::cout << "delete" << std::endl;
    delete pInvestment;
}

int main()
{
    {
        std::unique_ptr<Test> uptr = std::unique_ptr<Test>(new Test(10));
        auto size = sizeof(uptr);
        std::unique_ptr<Test> uptr1 = std::move(uptr);
        std::shared_ptr<Test> sptr2 = std::move(uptr1);
        //     std::cout << "over" << std::endl;
    }
    {
        Investment *ptr = makeInvestment_test(1);
        Investment *ptr2 = makeInvestment_test2(1);
        std::cout << "over";
    }
    {
        std::unique_ptr<Investment> uptrS = makeInvestment(1);
        //     auto size = sizeof(uptrS);
        //     std::unique_ptr<Investment> uptrB = makeInvestment(1, 2);
        //     std::unique_ptr<Investment> uptrR = makeInvestment(1, 2, 3);
    }
    {
        auto uptrS = makeInvestment2(1);
        //     auto size = sizeof(uptrS);
        //     std::unique_ptr<Investment, decltype(delInvmt)> uptrB = makeInvestment2(1, 2);
        //     std::unique_ptr<Investment, decltype(delInvmt)> uptrR = makeInvestment2(1, 2, 3);
    }

    // {
    //     auto uptrS = makeInvestment3(1);
    //     auto size = sizeof(uptrS);
    //     auto uptrB = makeInvestment3(1, 2);
    //     auto uptrR = makeInvestment3(1, 2, 3);
    // }

    // {
    //     std::unique_ptr<Investment, void (*)(Investment *)> uptr(nullptr, delInvmt3);
    //     std::unique_ptr<Investment, decltype(delInvmt)> uptr2(nullptr, delInvmt);
    //     auto size = sizeof(uptr);
    //     size = sizeof(uptr2);
    //     std::cout << "over";
    // }
    std::cout << "over" << std::endl;
    return 0;
}