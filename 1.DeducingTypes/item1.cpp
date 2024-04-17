#include <iostream>

// template <typename T>
// void f1(T param){}
// 顶const和不加一样
// template <typename T>
// void f2(const T param){}

// template <typename T>
// void f3(T *param){}
// 顶const,和不加一样
// template <typename T>
// void f4(T *const param){}

// template <typename T>
// void f5(const T *param){}
// 顶const,和不加一样
// template <typename T>
// void f6(const T *const param){}

template <typename T>
void f7(T& param){}

bool f(int,int);

int main(){
    #pragma region // ParamType=T
    #if 0
    int a=10;
    const int ca=11;
    // 顶const被忽略，全是int
    f1(a);
    f1(ca);
    int *pa=&a;
    int *const pca=&a;
    // 全是int*
    f1(pa);
    f1(pca);
    const int *cpa=&a;
    const int *const cpca=&a;
    // const int*
    f1(cpa);
    f1(cpca);
    int &ra=a;
    const int &rca=a;
    // ParamType既不是指针也不是引用
    // expr如果是引用就忽略引用
    // 引用只是别名,然后这里是值传递
    // 所以相当于ra和rca被copy了一份新的,当然不会保留const特性
    // 所以这里两个都是int
    f1(ra);
    f1(rca);
    int &&rr=std::move(a);
    const int &&rcr=std::move(a);
    // 右值引用也是引用,所以同上,全是int
    f1(rr);
    f1(rcr);
    int arr[10];
    f1(arr);
    int (*parr)[10];
    // 指向数组的指针
    f1(parr);
    int arr2[2]={1,2};
    int (&rarr)[2]=arr2;
    // 把引用忽略掉,他就是个数组,再退化成指针
    f1(rarr);
    bool fa(int,int);
    // 函数名退化成指针
    f1(fa);
    bool (*pfa)(int,int);
    f1(pfa);
    bool (&rfa)(int,int)=f;
    // 指向函数的指针,原因同上
    f1(rfa);
    // int
    f1(10);
    // const char*
    f1("hello");
    #endif
    #pragma endregion

    #pragma region // ParamType=T*
    #if 0
    int a=10;
    const int ca=11;
    // 不是指针,报错
    // f3(a);
    // f3(ca);
    int *pa=&a;
    int *const pca=&a;
    // 全是int*
    f3(pa);
    f3(pca);
    const int *cpa=&a;
    const int *const cpca=&a;
    // const int*
    f3(cpa);
    f3(cpca);
    int &ra=a;
    const int &rca=a;
    // 忽略引用后剩int,形参是指针类型,因此报错
    f3(ra);
    f3(rca);
    int &&rr=std::move(a);
    const int &&rcr=std::move(a);
    // 报错,原因同上
    f3(rr);
    f3(rcr);
    int arr[10];
    f3(arr);
    int (*parr)[10];
    // 指向数组的指针
    f3(parr);
    int arr2[2]={1,2};
    int (&rarr)[2]=arr2;
    // 把引用忽略掉,他就是个数组,再退化成指针
    f3(rarr);
    bool fa(int,int);
    // 函数名退化成指针
    f3(fa);
    bool (*pfa)(int,int);
    f3(pfa);
    bool (&rfa)(int,int)=f;
    // 指向函数的指针,原因同上
    f3(rfa);
    // 实参int,形参int*,报错
    f3(10);
    // const char*
    f3("hello");
    #endif
    #pragma endregion
    
    #pragma region // ParamType=const T*
    #if 0
    int a=10;
    const int ca=11;
    // 不是指针,报错
    f5(a);
    f5(ca);
    int *pa=&a;
    int *const pca=&a;
    // 全是const int*
    f5(pa);
    f5(pca);
    const int *cpa=&a;
    const int *const cpca=&a;
    // const int*
    f5(cpa);
    f5(cpca);
    int &ra=a;
    const int &rca=a;
    // 忽略引用后剩int,形参是指针类型,因此报错
    f5(ra);
    f5(rca);
    int &&rr=std::move(a);
    const int &&rcr=std::move(a);
    // 报错,原因同上
    f5(rr);
    f5(rcr);
    int arr[10];
    // const int*
    f5(arr);
    int (*parr)[10];
    // 指向数组的指针
    f5(parr);
    int arr2[2]={1,2};
    int (&rarr)[2]=arr2;
    // 把引用忽略掉,他就是个数组,再退化成指向首地址的指针
    f5(rarr);
    bool fa(int,int);
    // 函数指针没有必要底const,所以这里都报错
    f5(fa);
    bool (*pfa)(int,int);
    f5(pfa);
    bool (&rfa)(int,int)=f;
    // 指向函数的指针,原因同上
    f5(rfa);
    // 实参int,形参int*,报错
    f5(10);
    // const char*
    f5("hello");
    #endif
    #pragma endregion

    #pragma region // ParamType=T&
    // #if 0
    int a=10;
    const int ca=11;
    // int&
    f7(a);
    f7(ca);
    int *pa=&a;
    int *const pca=&a;
    // int *&
    f7(pa);
    // 这里还有疑问
    f7(pca);
    const int *cpa=&a;
    const int *const cpca=&a;
    // const int*
    f7(cpa);
    f7(cpca);
    int &ra=a;
    const int &rca=a;
    // 忽略引用后剩int,形参是指针类型,因此报错
    f5(ra);
    f5(rca);
    int &&rr=std::move(a);
    const int &&rcr=std::move(a);
    // 报错,原因同上
    f5(rr);
    f5(rcr);
    int arr[10];
    // const int*
    f5(arr);
    int (*parr)[10];
    // 指向数组的指针
    f5(parr);
    int arr2[2]={1,2};
    int (&rarr)[2]=arr2;
    // 把引用忽略掉,他就是个数组,再退化成指向首地址的指针
    f5(rarr);
    bool fa(int,int);
    // 函数指针没有必要底const,所以这里都报错
    f5(fa);
    bool (*pfa)(int,int);
    f5(pfa);
    bool (&rfa)(int,int)=f;
    // 指向函数的指针,原因同上
    f5(rfa);
    // 实参int,形参int*,报错
    f5(10);
    // const char*
    f5("hello");
    // #endif
    #pragma endregion
}