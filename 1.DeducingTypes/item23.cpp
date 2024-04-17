#include <iostream>
#include <memory>
#include <type_traits>

template <typename T>
T &&mymove(T &&param){
    return static_cast<T&&>(param);
}

template <typename T>
typename std::remove_reference<T>::type&&
mymove2(T &&param){
    using ReturnType=typename std::remove_reference<T>::type &&;
    return static_cast<ReturnType>(param);
}

struct A{
    A(int value):b(value){
        std::cout<<"create"<<std::endl;
    }
    A(const A &a){
        std::cout<<"copy"<<std::endl;
        b=a.b;
    }
    A(A &&a){
        std::cout<<"move"<<std::endl;
        b=a.b;
        a.b=0;
    }
    int b;
};

class Annotation{
public:
    explicit Annotation(const A a):a_param(std::move(a)){}
private:
    A a_param;
};

// template <typename T>
// void logprocess(T &&param){
//     process(param);
// }

template <typename T>
void logprocess(T &&param){
    process(std::forward<T>(param));
}

void process(const A &lval){
    std::cout<<"lval"<<std::endl;
}

void process(A &&rval){
    std::cout<<"rval"<<std::endl;
}

int main(){
    #if 0
    int mm=10;
    // 这里T推导为int
    int &&m1=mymove(10);
    /*
        传入左值，T被推导为int&，param也被推导为int&
        int& &&引用折叠下还是int&
        所以强制转换还是int&，返回的也是int&
        但是主函数里我们用右值引用接受一个左值引用，因此报错
    */
    int &&m2=mymove(mm);

    /*
        mymove2中使用std::remove_reference<T>去掉了T中的引用
        因此T&&就一定代表右值引用，而不会发生引用折叠
    */
    int &&m3=mymove2(10);
    int &&m4=mymove2(mm);

    // Annotation aa{10};
    const A a{10};
    A mm=std::move(a);
    #endif

    A a{10};
    logprocess(a);
    logprocess(std::move(a));

}