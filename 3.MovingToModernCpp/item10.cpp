#include <iostream>
#include <string>
// #include <tuple>

// enum作用域是全局的
enum Color{
    black=5,
    white,
    red
};

// 可以隐式的转换为整型
int a=red;

// 如果想前置声明，声明和定义处都要指明类型
enum School:int;
// 限域enum直接声明就好，默认是int
enum class EnumInt;

class A{
private:
    School _enumSchool;
    EnumInt kkk;
};

enum School:int{
    teacher,
    student
};

enum class EnumInt{
    e1=1,
    e2,
    e3
};

int main(){
    // 限域，要使用作用域运算符
    EnumInt aa=EnumInt::e1;
    return 0;
}