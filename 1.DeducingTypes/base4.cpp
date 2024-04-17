#include <iostream>

// 这个要内存对齐
struct Test1{
    int a;
    short b;
    int c;
    short d;
};

struct Test2{
    int a;
    int b;
    short c;
    short d;
};

int main(){
    Test1 t1;
    Test2 t2;
    std::cout<<sizeof(t1)<<std::endl;
    std::cout<<sizeof(t2)<<std::endl;
}