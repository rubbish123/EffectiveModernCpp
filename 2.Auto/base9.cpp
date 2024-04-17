#include <cassert>
#include <iostream>
#include <vector>

template <typename Derived>
struct Base{
    void name(){
        (static_cast<Derived*>(this))->impl();
    }
};

struct D1:public Base<D1>{
    void impl(){
        std::cout<<"D1::impl"<<std::endl;
    }
};

struct D2:public Base<D2>{
    void impl(){
        std::cout<<"D2::impl"<<std::endl;
    }
};

template <typename Derived>
void func(Base<Derived> derived){
    derived.name();
}

template <typename E>
class VecExpression{
public:
    double operator[](size_t i)const{
        return static_cast<E const&>(*this)[i];
    }
    size_t size()const{
        return static_cast<E const&>(*this).size();
    }
};

class Vec:public VecExpression<Vec>{
    std::vector<double> elems;

public:
    double operator[](size_t i)const{
        return elems[i];
    }
    double &operator[](size_t i){
        return elems[i];
    }
    size_t size()const{
        return elems.size();
    }
    Vec(size_t n):elems(n){}
    Vec(std::initializer_list<double> init){
        for(auto i:init){
            elems.push_back(i);
        }
    }

    template <typename E>
    Vec(VecExpression<E> const &vec):elems(vec.size()){
        for(size_t i=0;i!=vec.size();i++){
            elems[i]=vec[i];
        }
    }
};

template <typename E1,typename E2>
class VecSum:public VecExpression<VecSum<E1,E2>>{
    E1 const &_u;
    E2 const &_v;

public:
    VecSum(E1 const &u,E2 const &v):_u(u),_v(v){
        assert(u.size()==v.size());
    }
    double operator[](size_t i){
        return _u[i]+_v[i];
    }
    size_t size(){
        return _v.size();
    }
};

template <typename E1,typename E2>
VecSum<E1,E2> const operator+(E1 const &u,E2 const &v){
    return VecSum<E1,E2>(u,v);
}

int main(){
    Base<D1> derived1;
    Base<D2> derived2;
    D1 derived3;
    D2 derived4;

    func(derived1);
    func(derived2);
    func(derived3);
    func(derived4);

    Vec v0={1.0,1.0,1.0};
    Vec v1={2.0,2.0,2.0};
    Vec v2={3.0,3.0,3.0};

    auto v4=v0+v1;
    auto v5=v4+v2;
}