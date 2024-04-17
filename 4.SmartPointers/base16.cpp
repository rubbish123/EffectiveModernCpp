#include <iostream>

class Test{
public:
    Test(){
        std::cout<<"constructor:"<<this<<std::endl;
    }
    ~Test(){
        std::cout<<"destroyed:"<<this<<std::endl;
    }
};

int main(){
    // for(int i=0;i<3;i++){
    //     int *a=new int(10);
    //     // 三个地址相差很远 
    //     std::cout<<a<<std::endl;
    // }
    // // 这里三个地址紧凑
    // int *a=new int[3]{1,23,5};
    // std::cout<<a<<std::endl;
    // std::cout<<a+1<<std::endl;
    // std::cout<<a+2<<std::endl;
    // Test k;
    Test *t=new Test[3];
    delete[] t;
    int *a=new int[3];
    delete[] a;
    return 0;
}