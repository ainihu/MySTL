//
// Created by pip on 12/10/18.
//

/*
 * operator=:赋值
 * assign:赋值
 * at:取出元素指定位置的元素
 * operator[]:和at一样
 * front:取出第一个元素
 * back:取出最后一个元素
 * _data:返回指向vector中第一个数据的指针,或空vector之后的位置
 * begin \ cbegin
 * end \ cend
 * rbegin \ crbegin
 * rend \ crbegin
 * empty:判断vector是否为空
 * size:返回vector的大小
 * max_size
 * reserve
 * capacity
 * shrink_to_fit:减少capacity,但是不影响size
 * clear:清空向量,影响size
 * insert:插入数据
 * emplace
 * erase:删除元素
 * push_back:尾端添加元素
 * emplace_back
 * pop_back:弹出尾端元素
 * resize:改变元素个数
 * swap:交换两个向量的内的元素
 * operator==:判断两个向量是否相等
 * operator!=:判断两个向量是否不相等
 * operator<:判断向量是否小于
 * operator<=:判断向量是否小于等于
 * operator>:判断向量是否大于
 * operator>=:判断向量是否大于等于
 *
 *
 * */


#ifndef MYSTL_MYVECTOR_H
#define MYSTL_MYVECTOR_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using std::ostream;
using std::out_of_range;
using std::domain_error; // 执行一段程序的先决条件不满足

template <typename T>
class MyVector {
private:
    int _capacity; // 向量的容量
    int _size; // 数据的个数
    T *_data; // 数据指针

public:
// 特殊函数
    // 有参构造函数 用explicit修饰表示不使用隐式类型转换
    MyVector(int size = 0) {
        if (0 >= size) {
            this->_capacity = 0;
            this->_size = 0;
            this->_data = NULL;
        } else {
            this->_data = new T[size];
            if (NULL == this->_data) // 如果申请内存失败
                size = 0;
            this->_capacity = size;
            this->_size = size;
        }
    }

    // 有参构造函数
    MyVector(int size, T v) {
        if (0 >= size) {
            this->_capacity = 0;
            this->_size = 0;
            this->_data = NULL;
        } else {
            this->_data = new T[size];
            if (NULL == this->_data)
                size = 0;
            this->_size = size;
            this->_capacity = size;
            for (int i = 0; i < size; ++i) {
                this->_data[i] = v;
            }
        }
    }

    // 赋值拷贝构造函数
    MyVector(const MyVector &v) {
        if (0 == v._capacity) {
            this->_capacity = 0;
            this->_size = 0;
            this->_data = NULL;
            return;
        } else {
            int size = 0;
            this->_data = new T[v._capacity];
            if (NULL == this->_data) {
                this->_capacity = 0;
                this->_size = 0;
                return;
            }
            // 初始化,分配内存,拷贝数据
            this->_size = v._size;
            this->_capacity = v._capacity;
            for (int i = 0; i < v._size; ++i) {
                this->_data[i] = v._data[i];
            }
        }

    }

    //析构函数
    ~MyVector() {
        if (NULL == this->_data)
            delete[]this->_data;
        this->_data = NULL;
        this->_size = 0;
        this->_capacity = 0;
    }


// 成员函数
    // operator=赋值语句
    MyVector &operator=(MyVector &v) {
        if (&v == this) // 如果是自己给自己赋值,直接return
            return *this;

        if (this->_data != NULL) // 释放原来的内存
            delete[]this->_data;

        // 初始化,分配内存
        this->_data = new T[v._capacity];
        if (NULL == this->_data) {// 申请内存失败
            v._size = 0;
            v._capacity = 0;
            return *this;
        }
        this->_size = v._size;
        this->_capacity = v._capacity;


        // 拷贝数据
        for (int i = 0; i < this->_size; ++i) {
            this->_data[i] = v._data[i];
        }
        return *this;
    }

    // 填充
    void assign(int size, T v) {
        int resize = size;

        // 内存空间不够重新配置
        if (this->_capacity < size) {
            resize *= 2;
            delete[]this->_data;
            this->_data = new T[resize];
            if (NULL == this->_data) {
                resize /= 2;
                this->_data = new T[resize];
            }
            // 初始化
            this->_capacity = resize;
            this->_size = size;
        }
        // 赋值
        for (int i = 0; i < size; ++i) {
            this->_data[i] = v;
        }
    }


// 元素存取
    // at 函数
    T &at(int index) {
        if (index >= this->_size || index < 0)
            throw out_of_range("out of range");
        return this->_data[index];
    }

    // operator[]
    T &operator[](int index) {
        return this->at(index);
    }

    // 获取front
    T &front() {
        if (this->_size == 0) {
            throw out_of_range("size is zero");
        } else {
            return this->_data[0];
        }
    }

    // 获取back
    T &back() {
        if (this->_size == 0) {
            throw out_of_range("size is zero");
        } else {
            return this->_data[this->_size - 1];
        }
    }

    // 获取data指针, C++
    T *data() const {
        return this->_data;
    }

// 容量

    // 是否为空
    bool empty() const {
        return this->_size == 0;
    }

    // 获取size
    int size() const {
        return this->_size;
    }

    // 重新配置大小
    void reserve(int size) {
        if (this->_size < size) {
            T *tmp = new T[size];
            if (NULL == tmp)
                return;
            // 复制原来的数据
            for (int i = 0; i < this->_size; ++i) {
                tmp[i] = this->_data[i];
            }

            delete[]this->_data; // 释放原来的内存
            this->_data = tmp;
            this->_capacity = size;
        }
    }

    // 获取容量
    int capacity() const {
        return this->_capacity;
    }

    // 释放不必要内存
    void shrink_to_fit() {
        if (this->_size < this->_capacity) {
            T *tmp = new T[this->_size];
            if (NULL == tmp)
                return;
            for (int i = 0; i < this->_size; ++i) {
                tmp[i] = this->_data[i];
            }

            delete[]this->_data; // 释放原来的内存
            this->_data = tmp;
            this->_capacity = this->_size;
        }
    }

// 修改器

    // 清空容器,懒
    void clear() {
        this->_size = 0;
    }

    // insert
    void insert(int pos, T value) {
        if (pos < 0 || pos > this->_size)
            return;
        if ((this->_size + 1) > this->_capacity)
            this->reserve(this->_size * 2); // 二倍内存
        for (int i = this->_size; i >= pos; --i) {
            if (i == pos) {
                this->_data[i] = value;
            } else {
                this->_data[i] = this->_data[i - 1];
            }
        }
        this->_size++;
    }

    // erase
    T erase(int pos) {
        if (pos < 0 || pos >= this->_size)
            throw out_of_range("out of range");
        for (int i = 0; i < this->_size - 1; ++i) {
            if (i == pos)
                this->_data[i].~T(); // 显式调用析构函数,防止内存泄漏
            if (i >= pos)
                this->_data[i] = this->_data[i + 1];
        }
        --this->_size;

    }

    // push_back
    void push_back(T value) {
        if ((this->_size + 1) > this->_capacity)
            this->reserve(this->_size * 2);
        this->_data[this->_size] = value;
        this->_size++;
    }

    // pop_back
    void pop_back() {
        if (this->_size == 0)
            throw out_of_range("out of range");
        this->_size--;
        this->_data[this->_size].~T(); // 显式调用析构函数,防止内存泄漏
    }

    // resize(int)
    void resize(int size){
        if(this->_size >= size)
            this->_size = size;
        else
            throw domain_error("size must less than _size");
    }

    // resize(int, T)
    void resize(int size, T value){
        if (this->_size > size)
            this->_size = size;
        else{
            if(size > this->_capacity)
                this->reserve(size * 2);
            // 填充值
            for (int i = this->_size; i < size; ++i) {
                    this->_data[i] = value;
            }
            this->_size = size;
        }
    }

    // swap交换
    void swap(MyVector & value){
        if(&value == this)
            return;
        MyVector tmp = value;
        value = *this;
        *this = tmp;
    }

// operator
    // operator <<, 链式编程
    friend ostream &operator<<(ostream &out, MyVector &v) {
        for (int i = 0; i < v._size; ++i) {
            out << v[i] << " ";
        }
        return out;
    }

    // operator ==
    bool operator==(const MyVector & value){
        int i = 0;
        if(value._size != this->_size)
            return false;
        for (i = 0; i < this->_size; ++i) {
            if(this->_data[i] == value._data[i])
                continue;
            break;
        }
        return i == this->_size ? true: false;
    }

    // operator !=
    bool operator!=(MyVector & value){
        return !(*this == value);
    }

    // operator<
    bool operator<(MyVector & value){
        int i = 0;
        int size = this->_size < value._size ? this->_size:value._size;
        for (i = 0; i < size; ++i) {
            if (this->_data[i] < value._data[i])
                continue;
            break;
        }
        return i == size ? true: false;
    }

    // operator<=
    bool operator<=(MyVector & value){
        int i = 0;
        int size = this->_size < value._size ? this->_size : value._size;
        for (i = 0; i < size; ++i) {
            if (this->_data[i] <= value._data[i])
                continue;
            break;
        }
        return i == size ? true: false;
    }

    // operator>
    bool operator>(MyVector & value){
        return !(*this <= value);
    }

    // operator>=
    bool operator>=(MyVector & value){
        return !(*this < value);
    }
};


#endif //MYSTL_MYVECTOR_H
