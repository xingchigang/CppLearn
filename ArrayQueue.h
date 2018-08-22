//
// Created by xingc on 2018/8/15.
//
//队列的数组实现
#ifndef CPPLEARN_ARRAYQUEUE_H
#define CPPLEARN_ARRAYQUEUE_H

#include <iostream>

template <typename T, int size>
class ArrayQueue {
public:
    ArrayQueue() {
        first = last = -1; //负数下标相当于c中的指针运算，这里就是使用的两个双指针；
    }

    void enqueue(T el) {
        if (isFull()) {
            if (last == size-1 || last == -1){
                stroage[0] = el;
                last = 0;
                if (first == -1) {
                    first = 0;
                }
            }
            else stroage[++last] = el;
        }
        else std::cout << "Full queue!" << std::endl;
    }

    T dequeue() {
        T temp;
        temp = stroage[first];
        if (first == last){
            last = first = -1;
        }
        else if (first = size) {
            first = 0;
        } else first++;
        return temp;
    }

    bool isFull() {
        return first == 0 && last == size-1 || first == last+1;
    }

    bool isEmpty() {
        return first == -1;
    }

private:
    int first, last; //数组中的两个下标，相当于队列中的一头一尾
    T stroage[size];

};
#endif //CPPLEARN_ARRAYQUEUE_H
