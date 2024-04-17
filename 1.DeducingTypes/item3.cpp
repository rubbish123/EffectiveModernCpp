#include <iostream>

int f(int,double);

int main(){
    // decltype+变量 所有信息都会被保留，例如const
    // 数组和函数也不会退化
    const int a=5;
    int arr[5];
    decltype(a) b1=10;
    decltype(arr) b2;
    decltype(f) b3;

}