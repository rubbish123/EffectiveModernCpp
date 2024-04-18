#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test{};

int main(){
    #if 0
    unique_ptr<Test> up1=make_unique<Test>();
    unique_ptr<Test> up2(new Test);
    cout<<"up1="<<up1.get()<<endl;
    cout<<"up2="<<up2.get()<<endl;
    // 左值赋值和构造都是不可以的
    // up1=up2;
    // unique_ptr<Test> up3(up1);

    // 使用右值是可以的
    up1=std::move(up2);
    unique_ptr<Test> up3(std::move(up2));
    cout<<"up1="<<up1.get()<<endl;
    cout<<"up3="<<up3.get()<<endl;
    char c;
    auto deleter=[c](Test* t){
        cout<<"delete"<<endl;
        delete t;
    };
    unique_ptr<Test,decltype(deleter)> p;
    cout<<sizeof(p)<<endl;
    #endif
    puts(__PRETTY_FUNCTION__);
    return 0;
}