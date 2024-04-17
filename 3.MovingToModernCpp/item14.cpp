#include <vector>
#include <string>
#include <array>
#include <iostream>

struct A
{
    A(std::string param)
    {
        std::cout << "A(std::string param)" << std::endl;
        _data = param;
    }
    A(const A &a)
    {
        std::cout << "A(const A& a)" << std::endl;
        _data = a._data;
    }
    A(A &&a) noexcept
    {
        std::cout << "A(A&& a)" << std::endl;
        _data = std::move(a._data);
    }

public:
    std::string _data;
};

int main()
{
    std::vector<A> a_vec;
    a_vec.reserve(2);
    a_vec.push_back(A("nihao"));
    a_vec.push_back(A("nihao"));
    a_vec.push_back(A("nihao"));
    a_vec.push_back(A("nihao"));

    int a[10] = {0};
    int b[10] = {1};
    std::swap(a, b);

    return 0;
}