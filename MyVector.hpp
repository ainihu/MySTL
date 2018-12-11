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
 * data:返回指向vector中第一个数据的指针,或空vector之后的位置
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

template <typename T>
class MyVector {
private:
    int capacity; // 向量的容量
    int size; // 数据的个数
    T * data; // 数据指针
public:

// 特殊函数
    // 有参构造函数,用explicit修饰表示不使用隐式类型转换
    MyVector(int = 0){
        if(0 >= size)
        {
            this->capacity = 0;
            this->size = 0;
            this->data = NULL;
        }
        else
        {
            try {

            }
            catch (...)
            {
                throw ;
            }
        }
    }

    // 有参构造函数
    MyVector(int, MyVector &){

    }

    // 赋值拷贝构造函数
    MyVector(const MyVector & v){

    }
    //析构函数
    ~MyVector(){

    }


};


#endif //MYSTL_MYVECTOR_H
