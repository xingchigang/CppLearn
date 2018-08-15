//
// Created by xingc on 2018/8/14.
//
/*栈的向量实现*/
#ifndef CPPLEARN_VECTORSTACK_H
#define CPPLEARN_VECTORSTACK_H

#include <vector>
template <typename T, int capacity>
class VectorStack {
public:
    VectorStack() {
        pool.reserve(capacity);//vector中reserve()重新申请并改变当前vector对象总空间的大小；
        // 区别于resize()，这个只是改变vector中有效空间的大小；
    };

    void clear() {
        return clear();
    };

    bool isEmpty() const {
        return pool.empty();
    };

    T& topEL() {
        return pool.back();
    };

    T pop() {
        T el = pool.back(); //vector中的back()返回vector中最后一个元素的引用；
        pool.pop_back();
        return el;
    };

    void push(const T& el) {
        pool.push_back(el);
    };

private:
    std::vector<T> pool;
};


#endif //CPPLEARN_VECTORSTACK_H
