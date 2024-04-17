#include <iostream>

class Test{
public:
    void *operator new(std::size_t size){
        std::cout<<"operator new"<<std::endl;
        return malloc(size);
        /*
            这里如果要申请内存要么用malloc，要么用::operrator new
            直接new的话又会递归调用当前函数，死循环
        */
        // void *p=new Test;
    }
    void *operator new(std::size_t size,void *ptr){
        std::cout<<"placement new"<<std::endl;
        return ptr;
    }
};

int main(){
    void *p1=malloc(sizeof(Test)*10);
    free(p1);
    // int *p1=(int*)malloc(sizeof(Test)*10);
    // free((++p1));
    Test *t=new Test;
    std::cout<<sizeof(t)<<std::endl;
    Test *t2=new (static_cast<void*>(t))Test;
    std::cout<<sizeof(t2)<<std::endl;
    return 0;
}