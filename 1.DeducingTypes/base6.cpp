#include <iostream>

struct A{
    int a{20};
    void funcA(){
        std::cout<<"A::funcA"<<std::endl;
    }
};

struct B{
    int a{};
    void funcB(){
        std::cout<<"B::funcB"<<std::endl;
    }
};

struct CA:public A{
    int c{25};
    void funcCA(){
        std::cout<<"c is: "<<c<<std::endl;
        std::cout<<"CA::funcCA"<<std::endl; 
    }
};

struct Base
{
    virtual void func()
    {
        std::cout << "Base::func()" << std::endl;
    }
};

struct Derived : public Base
{
    virtual void func() override
    {
        std::cout << "Derived::func()" << std::endl;
    }
};


int main(){
    // 基本内置类型转换
    float f=10.f;
    int i=static_cast<int>(f);

    // 任意类型指针转换，要以void*作媒介
    A a;
    void *vap=static_cast<void *>(&a);
    int *ip=static_cast<int *>(vap);
    std::cout<<*ip<<std::endl;

    // 存在继承且没有多态的类之间转换
    // 上转可以下转不行
    CA ca;
    A a_=static_cast<A>(ca);
    a_.funcA();
    // 下转会报错
    // CA ca_=static_cast<CA>(a_);

    // 存在多态的类之间转换
    Base base;
    Derived derived;
    // 上转可以，没多态
    Base _base=static_cast<Base>(derived);
    _base.func();
    // 下转报错
    // Derived _derived=static_cast<Derived>(base);

    // 存在继承但不存在多态的类、指针之间互转，随便转，但是下转不安全
    CA *ca_=static_cast<CA *>(&a);
    // 这里下转不安全，因为ca中的c谁都不知道是多少
    ca_->funcCA();

    // 存在多态的类、指针之间互转
    Base *_baseptr=static_cast<Base *>(&derived);
    // 存在多态
    _baseptr->func();
    Derived *_derivedptr=static_cast<Derived *>(&base);
    // 这里下转不安全，调用的还是子类方法，因为base本来就是基类，它里面压根没子类的信息，转了也没用
    _derivedptr->func();
    Derived *__derived=static_cast<Derived *>(_baseptr);
    // 这里下转安全，调用的是子类的方法
    // 因为_baseptr原本就是子类指针上转上去得到的，现在再转回来没问题
    __derived->func();

    // 针对下转是否安全的问题，引入动态转换
    // 它将基类的指针或引用安全的转为其派生类的指针或引用,失败就是nullptr
    Derived *_dyderived=dynamic_cast<Derived *>(_baseptr);
    // 这里下行安全的
    _dyderived->func();
}