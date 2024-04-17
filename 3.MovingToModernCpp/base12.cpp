#include <iostream>
#include <string>
#include <vector>

namespace Meandi{
    class Building;
    class Laowang{
    public:
        Laowang();
        void visit();
    private:
        Building *m_building;
    };
    class Building{
    public:
        Building(std::string s,std::string m):sitting_room(s),m_bedroom(m){}
        std::string sitting_room;
    private:
        friend void Laowang::visit();
        std::string m_bedroom;
    };
    Laowang::Laowang(){}
}

int main(){}