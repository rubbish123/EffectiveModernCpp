#include <iostream>
#include <memory>

void f(int){
    std::cout<<"f(int)"<<std::endl;
}

void f(bool){
    std::cout<<"f(bool)"<<std::endl;
}

void f(void*){
    std::cout<<"f(void*)"<<std::endl;
}

int f1(std::shared_ptr<int> spi){
    return 5;
}

double f2(std::unique_ptr<int> upi){
    return 5;
}

bool f3(int *pi){
    return true;
}

template <typename FuncType,typename PtrType>
decltype(auto) func(FuncType f,PtrType ptr){
    return f(ptr);
}

int main(){
    int *aa=0;
    int *bb=NULL;
    int *cc=nullptr;

    auto a=0;
    // auto b=NULL;
    auto c=nullptr;

    f(0);
    // 编译不过，NULL是long类型，可以转成int bool和void*，编译器不知道匹配哪个
    // f(NULL);
    f(nullptr);

    auto result=func(f3,nullptr); // 正确
    // auto r2=func(f3,0); // 报错，传0，PtrType被推导为int，无法转成int*
    // 报错，可以用0直接初始化指针，但不能用变量
    int aaa=0;
    // int *m=aaa;
    return 0;
}