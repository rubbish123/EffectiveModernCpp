#include <iostream>

int main(){
    // a是一个常量
    const int a=10;
    // 用常量给int赋值，没错
    int b=a;

    // p是指针，有顶const和底const
    const int *const p=new int(10);
    // p1是指针，没有底const，意思是可以通过p1修改p所指的对象，和p有底const冲突
    int *p1=p;
    // p2有顶const无底const，冲突同上
    int *const p2=p;
    // p3有底const，不冲突
    const int *p3=p;

    // a是常量，p4无底const，冲突
    int *p4=&a;

    // r1有底const，没错
    const int &r1=20;
    // r2无底const，可通过r2修改a，和a是常量冲突
    int &r2=a;
    // r3无底const，r1有，冲突
    int &r3=r1;
}