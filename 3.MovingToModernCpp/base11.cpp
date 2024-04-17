#include <iostream>
#include <vector>

void strcpy(char *dest,const char *source){
    if(!dest||!source){
        throw std::invalid_argument("NULL pointers pass to strcpy");
    }
    while(*source){
        *dest++=*source++;
    }
    *dest='\0';
}

template <typename T>
class Array{
public:
    Array(std::size_t n)
    try:m_size(n),m_data(new T[n]){}
    catch(const std::bad_alloc &ba){
        std::cout<<"no enough memory"<<std::endl;
        throw;
    }
private:
    size_t m_size;
    int *m_data;
};

int main(){
    char *dest=nullptr;
    const char *source="hello";
    try{
        strcpy(dest,source);
    }
    catch(const std::logic_error &e){
        std::cout<<"hello"<<std::endl;
        std::cout<<e.what()<<std::endl;
    }
    catch(...){}
    return 0;
}