//
// Created by xingc on 2018/4/13.
//

#ifndef CPPLEARN_MAIN_H
#define CPPLEARN_MAIN_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(std::vector<T> vectorIn);

template <typename T>
void printVector(std::vector<T> vectorIn){
    typename std::vector<T>::iterator it;
    for (it = vectorIn.begin(); it != vectorIn.end(); ++it){
        std::cout << *it << " " ;
    }

}

template <typename T>
void print(T);

template <typename T>
void print(T result){
    std::cout << "The result is : " << result << std::endl;
}
#endif //CPPLEARN_MAIN_H

template <class genType, int size = 10> class genClass{
    genType storge[size];
};