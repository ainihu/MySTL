#include <iostream>
#include <vector>
#include "MyVector.hpp"

using std::cout;
using std::endl;
using std::vector;


int main() {
    MyVector<int> s;
    MyVector<int> s1(2, 3);
    auto s2 = s1;

    cout << "operator=:" << s2 << endl;
    s2.assign(3, 4);
    cout << "assign:" << s2 << endl;
    cout << "at:" << s2.at(1) << endl;
    cout << "operator[]:" << s2[1] << endl;
    cout << "front:" << s2.front() << endl;
    cout << "back:" << s2.back() << endl;
    cout << "data:" << *(s2.data() + 1) << endl;
    cout << "empty:" << s2.empty() << endl;
    cout << "size:" << s2.size() << endl;
    s2.reserve(7);
    s2.reserve(1);
    cout << "reserve:" << s2.capacity() << endl;
    s2.shrink_to_fit();
    cout << "shrink_to_fit:" << s2.capacity() << endl;
    cout << "s2:" << s2 << endl;
    s2.clear();
    cout << "clear:" << s2 << endl;
    s2.insert(0, 3);
    s2.insert(1, 2);
    s2.insert(2, 1);
    cout << "insert s2:" << s2 << endl;
    s2.erase(1);
    cout << "erase:" << s2 << endl;
    s2.push_back(9);
    cout << "push_back:" << s2 << endl;
    s2.insert(2, 1);
    cout << "****s2.insert(2, 1);" << endl;
    s2.pop_back();
    cout << "pop_back:" << s2 << endl;
    s2.resize(2);
    cout << "resize(int)" << s2 << endl;
    s2.shrink_to_fit();
    s2.resize(4, 2);
    cout << "resize(int, T)" << s2 << endl;
    return 0;
}