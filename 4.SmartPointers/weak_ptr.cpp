#include <iostream>
#include <memory>

using namespace std;

class A{};

int main(){
    shared_ptr<A> a1(new A);
    weak_ptr<A> weak_a1=a1;
    if(weak_a1.expired()){
        // 为true代表weak_a1对用的原生指针已经被释放
    }
    long a1_use_count=weak_a1.use_count(); // 引用计数
    if(shared_ptr<A> shared_a=weak_a1.lock()){
        // 成功就把weak_ptr提升为shared_ptr,失败就是一个nullptr的shared_ptr
    }
    weak_a1.reset(); // 置空
    return 0;
}