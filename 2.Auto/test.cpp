#include <iostream>

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

int main(){
    A a;
    A b=a;
    A c;
    b=c;
    A d=std::move(a);
    b=std::move(c);
    const A &e=std::move(a);
}