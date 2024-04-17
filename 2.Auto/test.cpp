#include <iostream>

using namespace std;

class A{
public:
    A(){
        std::cout<<"default constructor"<<std::endl;
    }
    A(const A &a){
        std::cout<<"copy constructor"<<std::endl;
    }
    A &operator=(const A &a){
        std::cout<<"copy operator"<<std::endl;
        return *this;
    }
};

class Base{
public:
    char a;
    int b;
    char c;
};

int main(){
    // A a;
    // A b=a;
    // A c;
    // b=c;
    // A d=std::move(a);
    // b=std::move(c);
    // const A &e=std::move(a);
    int a;
    char b,c;
    auto f=[b,a,c](){
        if(a>b){
            return a>c;
        }
    };
    cout<<sizeof(f)<<endl;

    // int arr[]={1,2,3,4,5};
    // std::cout<<[arr](){0;return 0;}()[arr]<<std::endl;
}