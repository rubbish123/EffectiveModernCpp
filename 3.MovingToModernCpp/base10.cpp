#include <iostream>
#include <string>

struct A{
    A(int param):a(param){
        b=50.f;
    }
    int a=10;
    float b=20.f;
    // 这个会被安插进构造函数
    std::string c{"hhh"};
};

struct B{
    B(){
        std::cout<<"B()"<<std::endl;
    }
    B(int data):data1(data){
        std::cout<<"B(int data)"<<std::endl;
    }
    virtual void vfunc(){
        std::cout<<"B::vfunc"<<std::endl;
    }
    int data1;
};

struct C{
    C(int data):data2(data){
        std::cout<<"C(int data)"<<std::endl;
    }
    B b;
    int data2;
};

// D中没有默认构造函数
struct D{
    D(int param):data4(param){}
    int data4;
};

// 子类需要手动初始化，就是不能不写D(d)
struct E:public D{
    E(int param,int d):D(d),data5(param){}
    int data5;
};

int main(){
    // c中数据成员b的构造先于c的构造函数
    C c(5);
}