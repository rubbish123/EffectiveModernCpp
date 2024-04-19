#include <iostream>

using namespace std;

class Test{
public:
    Test(int x){
        puts(__PRETTY_FUNCTION__);
    }
    Test(const Test&){
        puts(__PRETTY_FUNCTION__);
    }
    Test(Test&&){
        puts(__PRETTY_FUNCTION__);
    }
    Test& operator=(const Test&){
        puts(__PRETTY_FUNCTION__);
    }
    Test& operator=(Test&&){
        puts(__PRETTY_FUNCTION__);
    }
private:
    int a;
};

// Test getTest1(){
//     return Test(1);
// }

void getTest1(Test& test){
    new(&test)Test(1);
}

Test getTest2(){
    Test t(1);
    return t;
}

int main(){
    // Test t=getTest1();
    // char buf[sizeof(Test)];
    // Test* ptr=reinterpret_cast<Test*>(buf);
    // getTest1(*ptr);
    Test t=getTest2();
    return 0;
}