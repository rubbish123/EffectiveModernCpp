#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Test{};

int main(){
    shared_ptr<Test> a1(new Test);
    shared_ptr<Test> a2=a1; // 允许共享所有权
    Test* origin_a=a1.get(); // 尽量不要暴露原生指针
    if(a1){
        // a1拥有指针
    }
    if(a1.unique()){
        // 如果返回true,引用计数为1
    }
    long a1_use_count=a1.use_count(); // 引用计数数量
    cout<<sizeof(a1)<<endl;
    return 0;
}