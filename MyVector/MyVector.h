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
 * empty:判断vector是否为空
 * size:返回vector的大小
 * max_size返回
 * */


#ifndef MYSTL_MYVECTOR_H
#define MYSTL_MYVECTOR_H

class MyVector {
private:
    int capacity;
    int size;
};


#endif //MYSTL_MYVECTOR_H
