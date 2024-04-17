#include <iostream>

int get_value(){
    return 20;
}

int main(){
    int e=10;
    // 编译期常量
    const int a=10;
    const int b=1+2;
    // 运行时常量
    const int c=e;
    const int d=get_value();
    // constexpr 一定得到一个编译器常量，否则报错
    constexpr int mm=a;
}