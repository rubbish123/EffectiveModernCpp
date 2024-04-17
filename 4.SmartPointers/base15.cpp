#include <iostream>
#include <string>
#include <vector>

class Airplane
{
private:
    struct AirplaneRep
    {
        unsigned long miles{10}; // 8
        char type{'A'};          // 1       16
    };
    union
    {
        AirplaneRep rep{}; // 16
        Airplane *next;    // 8
    };                     // 16

public:
    unsigned long
    getMiles()
    {
        return rep.miles;
    }
    char getType() { return rep.type; }
    void set(unsigned long m, char t)
    {
        rep.miles = m;
        rep.type = t;
    }
    static void *operator new(size_t size);
    static void operator delete(void *ptr);
    ~Airplane() { std::cout << "Airplane::~Airplane()" << std::endl; }

private:
    static const int BLOCK_SIZE;
    static Airplane *headOfFreeList;
};

Airplane *Airplane::headOfFreeList;
const int Airplane::BLOCK_SIZE = 512;

void *Airplane::operator new(size_t size)
{
    // if (size != sizeof(Airplane))
    // {
    //     return ::operator new(size);
    // }
    Airplane *p = headOfFreeList;
    if (p)
    {
        headOfFreeList = p->next;
    }
    else
    {
        Airplane *newBlock = static_cast<Airplane *>(::operator new(BLOCK_SIZE * sizeof(Airplane)));
        for (int i = 1; i < BLOCK_SIZE - 1; ++i)
        {
            newBlock[i].next = &newBlock[i + 1];
        }
        newBlock[BLOCK_SIZE - 1].next = 0;
        p = newBlock;
        headOfFreeList = &newBlock[1];
    }
    return p;
}

void Airplane::operator delete(void *ptr)
{
    if (ptr == 0)
    {
        return;
    }
    // if (size != sizeof(Airplane))
    // {
    //     ::operator delete(ptr);
    //     return;
    // }
    Airplane *deleteMe = static_cast<Airplane *>(ptr);
    deleteMe->next = headOfFreeList;
    headOfFreeList = deleteMe;
}

int main()
{
    Airplane *p3 = new Airplane();
    auto size = sizeof(Airplane);
    std::cout << p3 << std::endl;
    // p3->set(1000, 'A');
    Airplane *p4 = new Airplane();
    std::cout << p4 << std::endl;
    // p4->set(5000, 'A');
    Airplane *p5 = new Airplane();
    std::cout << p5 << std::endl;

    delete p3;
    delete p5;
    delete p4;
    free(p3);
    // std::allocator<int> alloc;
    // alloc.allocate(10);
    return 0;
}