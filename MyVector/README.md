# MyVector
> 学习完泛型已经将近一年了,之前学习的时候写过一个vector使用,但是没有当一个项目来完成过,这里打算好好地写一下来,一方面作为复习的作用,一方面给自己找点事情干,由于学习完没有一点目标了.学习完C++自己又去学习了Python和Go但是都是浅尝辄止,并没有深入学习.所以实质性并没有学到多少东西,只是了解了基础的语法,谈不上做什么项目之类的.所以这里打算好好的写一写.未来一到两个月打算好好复习C++.

## MyVector设计
> 由于对空间配置器不太熟悉所以就使用new了,new的内存空间申请也是使用的空间配置器,参考[cpprefernce.com](https://en.cppreference.com/w/cpp/container/vector)的vector的方法和成员变量设计vector

## MyVector方法和成员变量

> 有些方法涉及到空间配置器和迭代器等,或者不会实现,但是会尽力实现写出来一个MyVector
> 参考链接[cppreference](https://en.cppreference.com/w/cpp/container/vector)


*   成员函数
    *   `operator=`
    *   `assign`
*   元素存取
    *   `at`
    *   `operator[]`
    *   `front`
    *   `back`
    *   `data(C++11)`
*   迭代器
    *   `begin \ cbegin`
    *   `end \ cend`
    *   `rbegin \ crbegin`
    *   `rend \ crend`

*   容量
    *   `empty`
    *   `size`
    *   `max_size`
    *   `reserve`
    *   `capacity`
    *   `shrink_to_fit`
    
*   修改器
    *   `clear`
    *   `insert`
    *   `emplace`
    *   `erase`
    *   `push_back`
    *   `emplace_back`
    *   `pop_back`
    *   `resize`
    *   `swap`
    
*   非成员函数
    *   `operator==`
    *   `operator!=`
    *   `operator<` 
    *   `operator<=`
    *   `operator>`
    *   `operator>=`