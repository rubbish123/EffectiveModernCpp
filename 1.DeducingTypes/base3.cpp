#include <iostream>

// 数组名作为参数传递时会退化为指针
void fun(int a[50]);

int main(){
    #if 0
    // arr的类型是int[5]
    int arr[5]={0,1,2,3,4};
    // 数组名退化成指向其首元素的指针
    int *ptr=arr;
    // 依然成立，ptr2是一个指向有五个int元素的数组的指针
    int (*ptr2)[5]=&arr;
    // 引用，int (&)[5]
    int (&ref)[5]=arr;

    char str[12]="hello world";
    std::cout<<&"hello world"<<std::endl;

    // "hello world"是const，应当用有底const的指针接收，但是这里一九可以接收
    char *str2="hello world";
    // 但是如果想通过指针修改"hello world"，就会报段错误
    str2[0]='o';
    std::cout<<str2<<std::endl;
    #endif
    
    return 0;
}