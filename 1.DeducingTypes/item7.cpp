#include <vector>
#include <string>
#include <array>
#include <iostream>

// struct people
// {
//     // people() = default;
//     int age;
//     std::string name;
//     float height;
// };

struct A
{
    A()
    {
        std::cout << "A()" << std::endl;
    }
    // A(int a)
    // {
    //     std::cout << "A(int a)" << std::endl;
    // }
    A(int a,int b)
    {
        std::cout << "A(int a)" << std::endl;
    }
    // A(int a, std::string b)
    // {
    //     std::cout << "A(int a, std::string b)" << std::endl;
    // }
    // A(int a, std::string name)
    // {
    //     std::cout << "A(int a, std::string name)" << std::endl;
    // }
    A(const A &a)
    {
        std::cout << "A(const A& a)" << std::endl;
    }
    A(std::initializer_list<int> a)
    {
        std::cout << "C(std::initializer_list<int> a)" << std::endl;
        for (const int *item = a.begin(); item != a.end(); ++item)
        {
        }
    }
};


void fun1(A arg)
{
}

A fun2()
{
    // return A(10,5);
    return {10, 5};
}

// most vexing parse
// TYPE b = (TYPE)a

void f(double value)
{
    // int i(int(value));
    int i{int(value)}; 
}


struct Timer
{
};

struct TimerKeeper
{
    TimerKeeper(Timer t) {}
};


struct S
{
    int x;
    int y;
};

template <typename T, size_t N>
struct MyArray
{
    T data[N];
};

class MyStringWithIndex : public std::string
{
public:
    int index = 0;
};


int main()
{
    // 一次普通构造，一次拷贝构造
    // A a = 10;
    // 普通构造
    // A b(10);
    // 普通构造和拷贝构造
    // A c = (10);
    // 普通构造
    // A d{10};
    // 普通构造
    // A e = {10};

    // A f = 10, 5;
    // A g(10, 5); 
    // A i = {10, 5};
    // A j = {10, 5};
    // fun1({10,5});
    // A MM = fun2();

    // fun1(g);
    // fun1({10, 5});
    // people aaa{10, "jif", 18.f};
    // people aaa{.name = "people"};
    TimerKeeper time_keeper{Timer()};
    // TimerKeeper time_keeper{Timer()};
    // std::vector<int> aaa{1, 2, 3, 4, 5};

    // A k{};
    // A l({});
    // A m{{}};

    // https://blog.csdn.net/devcloud/article/details/114523118
    #if 0
    int a1[3]{1, 2, 3}; // 简单类型，原生数组
    int a2[3] = {1, 2, 3};
    std::array<int, 3> a3{1, 2, 3};     // 简单类型，std::array
    std::array<int, 3> a4 = {1, 2, 3};  // 简单类型，std::array
    S a5[3] = {{1, 2}, {3, 4}, {5, 6}}; // 复合类型，原生数组
    S a6[3] = {1, 2, 3, 4, 5, 6};       // 大括号的省略

    std::array<S, 3>
        a7{{1, 2}, {3, 4}, {5, 6}};      // 复合类型，std::array，编译失败！
    // MyStringWithIndex s{"hello world", 1}; // c++17之前都会报错

    // std::vector<int> vec{1, 2, 3., 5, 6};
    #endif
    // 调用initializer_list
    // A aaaa{1,2};
    A aaaaaaa{};
    // A bbbbbbb({});
}
