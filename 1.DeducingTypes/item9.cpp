#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <type_traits>

struct test1{
    // 静态成员变量也可以用作用域运算符访问
    static int SubType;
};

struct test2{
    typedef int SubType;
};

template <typename T>
class Myclass{
public:
    void foo(){
        // 加typename表示这是个类型成员
        typename T::SubType *ptr;
        // T::SubType *ptr;
    }
};

// using语句可以使用模板
template <class T>
using myVector=std::vector<T>;
// myVector<int>

template <typename T>
class Widget{
public:
    // 使用using的话，就不用typename了
    myVector<T> list;
};

template <typename T>
struct myVector2{
    typedef std::vector<T> type;
};

template <typename T>
class Widget2{
public:
    // 这里不是using，而是用的作用域运算符，就要用typename
    typename myVector2<T>::type list;
};


int main(){
    // Myclass<test1> class1;
    // class1.foo();
    // Myclass<test2> class2;
    // class2.foo();
    Widget2<int> w2;
    myVector2<int>::type myvec2={1,2,3};
    return 0;
}