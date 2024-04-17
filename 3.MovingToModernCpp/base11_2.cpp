#include <vector>
#include <string>
#include <iostream>

// class Buffer
// {
// private:
//     unsigned char *_buf;
//     int _capacity;
//     int _length;

// public:
//     explicit Buffer(int capacity) : _capacity(capacity), _length(0)
//     {
//         std::cout << "Buffer(int capacity)" << std::endl;
//         // throw std::invalid_argument("=====");
//         _buf = capacity == 0 ? nullptr : new unsigned char[capacity]{};
//     }

//     ~Buffer()
//     {
//         std::cout << "~Buffer()" << std::endl;
//         delete[] _buf;
//     }

//     Buffer(const Buffer &buffer)
//     {
//         std::cout << "Buffer(const Buffer &buffer)" << std::endl;
//         this->_capacity = buffer._capacity;
//         this->_length = buffer._length;
//         // throw std::invalid_argument("=====");
//         this->_buf = new unsigned char[buffer._capacity];
//         std::copy(buffer._buf, buffer._buf + buffer._capacity, this->_buf);
//     }

//     Buffer(Buffer &&buffer) noexcept
//     {
//         std::cout << "Buffer(Buffer &&buffer)" << std::endl;
//         this->_capacity = buffer._capacity;
//         this->_length = buffer._length;
//         this->_buf = buffer._buf;

//         buffer._buf = nullptr;
//         buffer._capacity = 0;
//         buffer._length = 0;
//     }

//     Buffer &operator=(const Buffer &buffer)
//     {
//         std::cout << "Buffer &operator=(const Buffer &buffer)" << std::endl;
//         if (this != &buffer)
//         {
//             this->_capacity = buffer._capacity;
//             this->_length = buffer._length;
//             delete[] this->_buf;
//             throw std::invalid_argument("....");
//             this->_buf = new unsigned char[buffer._capacity];
//             std::copy(buffer._buf, buffer._buf + buffer._capacity, this->_buf);
//         }
//         return *this;
//     }

//     Buffer &operator=(Buffer &&buffer) noexcept
//     {
//         std::cout << "Buffer &operator=(Buffer &&buffer)" << std::endl;
//         if (this != &buffer)
//         {
//             this->_capacity = buffer._capacity;
//             this->_length = buffer._length;
//             delete[] this->_buf;
//             this->_buf = buffer._buf;

//             buffer._buf = nullptr;
//             buffer._capacity = 0;
//             buffer._length = 0;
//         }
//         return *this;
//     }

//     bool write(unsigned char value) noexcept
//     {
//         if (_length == _capacity)
//             return false;
//         _buf[_length++] = value;
//         return true;
//     }
// };

class Buffer{
private:
    unsigned char *_buf;
    int _capacity;
    int _length;
public:
    explicit Buffer(int capacity):
        _capacity(capacity),_length(0),
        _buf(capacity==0? nullptr:new unsigned char[capacity]){}
    ~Buffer(){
        delete[] _buf;
    }
    friend void swap(Buffer &lhs, Buffer &rhs);
    Buffer(const Buffer &buffer):
        _capacity(buffer._capacity),
        _length(buffer._length),
        _buf(_capacity==0? nullptr:new unsigned char[_capacity])
    {
        std::copy(buffer._buf,buffer._buf+buffer._capacity,this->_buf);
    }
    Buffer(Buffer &&buffer):Buffer(0){
        swap(buffer,*this);
    }
    Buffer &operator=(Buffer buffer){
        swap(*this,buffer);
        return *this;
    }
    
    bool write(unsigned char value) noexcept
    {
        if (_length == _capacity)
            return false;
        _buf[_length++] = value;
        return true;
    }
};

void swap(Buffer &lhs, Buffer &rhs)
{
    using std::swap;
    swap(lhs._buf, rhs._buf);
    swap(lhs._capacity, rhs._capacity);
    swap(lhs._length, rhs._length);
}

class BitMap
{
public:
    explicit BitMap(size_t size) : _buffer(size) {}
    static void Swap(BitMap &lhs, BitMap &rhs)
    {
        using std::swap;
        swap(lhs._buffer, rhs._buffer);
    }

private:
    Buffer _buffer;
};

int main()
{
    int *a = nullptr;
    Buffer buffer(10);
    buffer.write(52);
    buffer.write(37);
    Buffer buffer1(20);
    buffer1.write(20);
    buffer1.write(111);

    swap(buffer, buffer1);
    // try
    // {
    //     buffer1 = buffer;
    // }
    // catch (...)
    // {
    //     std::cout << "error" << std::endl;
    // }

    // buffer.write(52);
    // buffer.write(37);
    // Buffer buffer1(20);
    // buffer1.write(20);
    // buffer1.write(111);
    // try
    // {
    //     buffer1 = buffer;
    // }
    // catch (...)
    // {
    //     std::cout << "error" << std::endl;
    // }
    // std::cout << "over" << std::endl;
}

// Buffer buffer = Buffer(10);
// buffer = Buffer(16);
