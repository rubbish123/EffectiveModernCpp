#include <iostream>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

class Test{};

void mydeleter(Test* t){}

int main(){
    char a='a';
    char kkk='b';
    char c='c';
    char d='c';
    int b=42;
    unique_ptr<Test> a1(new Test);
    unique_ptr<Test> a2=make_unique<Test>();
    // a1=a2; // 错误，unique_ptr是move_only的
    a1=std::move(a2); // move可以

    Test* origin_ptr=a1.get(); // 尽量不要暴露原生指针
    unique_ptr<Test> a3(a1.release()); // 转移拥有权
    a3.reset(new Test); // 释放并销毁原有对象,持有一个新对象
    a3.reset(); // 释放并销毁原有对象
    a3=nullptr; // 同上

    // unique_ptr可以用于数组
    unique_ptr<int[]> a4=make_unique<int[]>(10);
    for(int i=0;i<10;i++){
        a4[i]=i*i;
    }
    unique_ptr<Test> a5;
    cout<<sizeof(a5)<<endl;
    auto lambda=[=](Test*){
        cout<<a<<kkk<<c<<d<<b<<endl;
    };
    unique_ptr<Test,decltype(lambda)> a6(new Test(),lambda);
    cout<<sizeof(a6)<<endl;
    cout<<sizeof(function<void()>)<<"---------"<<endl;
    unique_ptr<Test,decltype(mydeleter)*> a7(new Test,mydeleter);
    cout<<sizeof(a7)<<endl;
    return 0;
}