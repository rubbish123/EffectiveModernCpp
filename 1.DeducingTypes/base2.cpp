#include <iostream>
#include <string.h>
#include <string>

// copy from 【现代 C++ 语言核心特性解析】
class BigMemoryPool
{
public:
    static const int PoolSize = 4096;
    BigMemoryPool() : pool_(new char[PoolSize]) {}
    ~BigMemoryPool()
    {
        if (pool_ != nullptr)
        {
            delete[] pool_;
        }
    }
    BigMemoryPool(BigMemoryPool &&other)
    {
        std::cout << "move" << std::endl;
        pool_ = other.pool_;
        other.pool_ = nullptr;
    }
    BigMemoryPool(const BigMemoryPool &other) : pool_(new char[PoolSize])
    {
        std::cout << "copy" << std::endl;
        memcpy(pool_, other.pool_, PoolSize);
    }

private:
    char *pool_;
};

BigMemoryPool getPool()
{
    BigMemoryPool memoryPool;
    return memoryPool;
}

BigMemoryPool getPool(const BigMemoryPool aa)
{
    return aa;
}
BigMemoryPool get_pool(const BigMemoryPool &pool)
{
    return pool;
}
// BigMemoryPool tmp = pool;

BigMemoryPool make_pool()
{
    BigMemoryPool pool;
    return get_pool(pool);
}
//  BigMemoryPool tmp2 = tmp;

int gx = 10;
int get_gx()
{
    return gx;
}

int get_x()
{
    int x = 20;
    return x;
}


int main()
{
    #if 0
    // 所有的字面量都是右值，除了字符串常量

    // 两次copy
    BigMemoryPool aaa=getPool();
    // 返回的是右值，不能取地址
    // &get_x();
    // 没有底const的左值引用不接受右值，因此报错
    // int &y=get_x();
    // 右值引用可以正常接收右值
    int &&y=get_x();
    int x=10;
    // 后置++不能取地址，前置加加可以取地址
    // int *p1=&x++;
    // int *p2=&++x;


    // aaa是左值，所以这里还是执行拷贝构造
    BigMemoryPool ccc=aaa;
    // std::move() 将左值转为右值,把左值的生命周期结束,这里用完aaa就寄了
    // 通过左值转为的右值就是将亡值
    BigMemoryPool ddd=std::move(aaa);
    // 如果类中没实现移动构造函数，那么std::move()之后依然使用拷贝构造函数
    /*
        因此拷贝构造函数的参数是一个const的引用，可以接收右值引用
    */
    BigMemoryPool eee=std::move(aaa);

    /*
        右值绑定到右值引用上，这里不会发生任何拷贝和移动
        因此std::move()之后是右值，使用一个右值引用接收
        这种写法就类似于使用左值引用接收左值，当然不会发生拷贝
    */
    BigMemoryPool &&fff=std::move(aaa);
    #endif
    BigMemoryPool hhh=make_pool();

    return 0;
}
