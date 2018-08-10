//
// Created by xingc on 2018/8/9.
//

#ifndef CPPLEARN_LINKEDLIST_H
#define CPPLEARN_LINKEDLIST_H


struct ListNode{
    void *key;
    ListNode *prev;
    ListNode *next;
};

template <typename T>
class LinkedList {
private:
    unsigned long eleSize;

public:
    /*构造函数*/
    LinkedList();
    /*清除链表*/
    void clrList(LinkedList *L, void (*proc)(void *));
    /*判断链表是否为空*/
    int isEmpty(LinkedList);
    /*遍历链表*/
    void listTravers(LinkedList L);
    /*在链表中查找*/
    ListNode listSearch(LinkedList)
    /*在节点a前插入节点k*/

    /*在链表中删除节点*/

    /*在表首插入节点*/

    /*在表尾插入节点*/


};


#endif //CPPLEARN_LINKEDLIST_H
