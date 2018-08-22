//
// Created by xingc on 2018/8/15.
//
//链表实现队列
#ifndef CPPLEARN_LISTQUEUE_H
#define CPPLEARN_LISTQUEUE_H

#include <list>

template <typename T>
class ListQueue {
public:
    ListQueue() {

    }

    void clear() {
        lst.clear();
    }

    bool isEmpty() const {
        return lst.empty();
    }

    T& front() {
        return lst.front();
    }

    T dequeue() {
        T el = lst.front();
        lst.pop_front();
        return el;
    }

    void enqueue(const T& el) {
        lst.push_back(el);
    }

private:
    std::list<T> lst;
};
#endif //CPPLEARN_LISTQUEUE_H
