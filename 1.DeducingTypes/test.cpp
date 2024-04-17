#include <iostream>

using namespace std;

int main(){
    int a=10;
    int b=20;
    int *ptr=&a;
    int *const aptr=&a;
    // aptr=&b;
    *aptr=5;
    int *&ptrref=ptr;
    int* const &kkk=aptr;
}