#include <iostream>

void func(int,int);

int func2(int){
    return 10;
}
int(*func2Ptr)(int)=func2;

template <typename T>
void f(T param){
    std::cout<<param<<std::endl;
}

// template <typename T>
// void f(T *param)
// {
//     std::cout << param << std::endl;
// }

// template <typename T>
// void f(T &param)
// {
//     std::cout << param << std::endl;
// }


int main(){
    // T被推导为int
    int a=10;
    f(a);
    // int*
    int *aptr=&a;
    f(aptr);
    // int,而不是int&
    int &aref=a;
    f(aref);
    // 右值引用也是引用，引用放在等号右边会被忽略，这里推出的还是int
    int &&arref=std::move(a);
    f(arref);

    // 顶层const，被忽略，依旧推导int
    const int ca=10;
    f(ca);
    // 底层const，不可被忽略，推导出const int*
    const int *captr=&ca;
    f(captr);
    // 引用加const全部忽略，推导出int
    const int &caref=ca;
    f(caref);
    // 同上
    const int &&carref=std::move(ca);
    f(carref);
    // 顶层const被忽略，得到int*
    int *const acptr=&a;
    f(acptr);
    
    // 忽略顶const，保留底const
    const int *const cacptr=&a;
    f(cacptr);
    // 字面量 int
    f(10);

    // 数组名退化为int*
    int arr[2]={0,1};
    f(arr);
    // 这个还不理解
    f("hello world");
    // 数组指针 int(*)[2]
    int (*arrptr)[2]=&arr;
    f(arrptr);
    // 引用，就是数组的别名，然后数组名退化为int*
    int (&arrref)[2]=arr;
    f(arrref);

    // 函数名退化为指针 void(*)(int,int)
    f(func);
    // 直接推导为指针
    void (*funcptr)(int,int)=func;
    f(funcptr);
    // 引用被忽略，函数名退化为指针
    void (&funcref)(int,int)=func;
    f(funcref);

    return 0;
}