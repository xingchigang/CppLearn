//
// Created by xingc on 2018/8/14.
//
//栈的链表实现
#ifndef CPPLEARN_LISTSTACK_H
#define CPPLEARN_LISTSTACK_H

#include <list>

template <typename T>
class ListStack {
public:
    ListStack() {

    }

    void clear() {
        lst.clear();
    }

    bool isEmpty()const {
        return lst.empty();
    }

    T pop() {
        T el = lst.back();
        lst.pop_back();
        return el;
    }

    void push(const T& el) {
        lst.push_back(el);
    }

private:
    std::list<T> lst;
};
#endif //CPPLEARN_LISTSTACK_H
