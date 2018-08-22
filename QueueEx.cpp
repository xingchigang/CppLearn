//
// Created by xingc on 2018/8/16.
//
//C++ STL中的队列练习
#include <iostream>
#include <queue>
#include <list>
#include <functional>

int Queuetest () {
    std::queue <int> q1;
    std::queue <int, std::list<int> > q2;
    q1.push(1); q2.push(4);
    q1.push(2); q2.push(5);
    q1.push(3); q2.push(6);
    q1.push(q2.back());
    while (!q1.empty()) {
        std::cout << q1.front() << ' ' << std::endl;
    }

    while (!q2.empty()) {
        std::cout << q2.front() << ' ' << std::endl;
        q2.pop();
    }
    return 0;
}

int PriorityQueuetest() {
    std::priority_queue<int> pq1;
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq2;
    pq1.push(3); pq2.push(3);
    pq1.push(1); pq2.push(1);
    pq1.push(2); pq2.push(2);
}
