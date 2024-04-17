#include <iostream>
#include <string>
#include <memory>

int a = 0;
class SizeComp
{
public:
    SizeComp(size_t n) : sz(n) {}
    bool operator()(const std::string &s) const { return s.size() >= sz; }

private:
    size_t sz;
};

class A
{
public:
    void print() { std::cout << "Class A" << std::endl; }
    void test()
    {
        // lambda可以不会this指针
        auto foo = [this]
        {
            print();
            x = 5;
        };
        foo();
    }

private:
    int x;
};

int main()
{
    size_t sz = 10, ss = 50;

    auto SizeCompLambda = [=](const std::string &a)
    {
        return a.size() >= sz;
    };
    // size=8 说明lambda可以捕获所有的局部变量，但是只有真正在函数体内部用到这个变量的时候才会捕获
    auto size = sizeof(SizeCompLambda);

    int b = 0;
    static int c = 0;

    // auto fun1 = [a, b, c] {};
    // lambda只需要捕获非静态局部变量 a c不需要被捕获 可以直接使用
    auto fun1 = [b]
    {
        std::cout << "b is : " << b << std::endl;
        a = 10;
        c = 12;
    };
    
    // 捕获在lambda定义的时候就发生了，这里是值捕获，所以函数体输出sz=10
    auto func_test = [&sz]()
    { std::cout << "sz is : " << sz << std::endl; };

    sz = 50;
    func_test();

    auto fun2 = [](int mm)
    {
        mm = 20;
        return mm;
    };
    auto ssize = sizeof(fun2);
    auto important = std::make_unique<int>(1);
    // 这种方式使得lambda可以捕获右值
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int
    {
        return x + y + v1 + (*v2);
    };

    auto fun3 = [b = b + 2] 
    {
        std::cout << "b is : " << b << std::endl;
    };

    // lambda里可以有多个return语句
    auto fun4 = [](int i)
    {if(i>0) return i; 
    else return -i; };

    // auto x2 = []()
    // { return {1, 2}; };

    auto mm = fun4(-10);
    auto ccc=[]{
        return 42;
    };
    std::cout<<ccc()<<std::endl;
    return 0;
}
