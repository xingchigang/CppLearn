//
// Created by xingc on 2018/8/10.
//

#ifndef CPPLEARN_LIBRARY_H
#define CPPLEARN_LIBRARY_H
/*图书馆案例*/
/*功能：向图书馆添加新书，读者借书，读者还书
 * 有一个包含图书馆中全部书籍作者的链表catalog，为加速查找过程：
 * 1.链表可以按照字母顺序排序，并且如果找到了所需的名字，或者找到的名字大于要找的名字，或者到
 *   达链表末尾，都可以停止查找。
 * 2.令一个指针数组指向Author，该结构用字母做索引，数组中每个单元都指向作者链表，作者的名字以及
 *   数组单元以同样的字母开头（本例中使用第二种方法）catalog['F']指向以 F开始的作者链表。
 * 书可以归还具体表现为：从还书人所借阅的链表中删除相应的节点。*/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <cstring>

//c++中的类需要交叉引用时需要前置声明：
class Book;
class CheckedOutBook;
class Patron;
class Author;

void includeBook();
void checkOutBook();
void status();
char *getString(char *msg);
void returnBook();
int menu();

class Patron {
private:
    char *name;
    std::list<CheckedOutBook> books;
    std::ostream& printPatron(std::ostream&) const; //函数名后加const表明他们不修改类对象；
    // 任何不修改数据成员的函数都应该声明为const类型；
    friend std::ostream& operator<< (std::ostream& out, const Patron& pn){
        return pn.printPatron(out);
    }
    friend void checkOutBook();
    friend void returnBook();
    friend Book;
public:
    Patron() {

    }
    bool operator== (const Patron& pn) const {
        return std::strcmp(name, pn.name);
    }
};

class Book {
private:
    char *title;
    Patron *patron;
    std::ostream &printBook(std::ostream&) const;
    friend std::ostream&operator<< (std::ostream& out, const Book& bk) {
        return bk.printBook(out);
    }
    friend class CheckedOutBook;
    friend Patron;
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();

public:
    Book(){
        patron = 0;
    }
    bool operator== (const Book &bk) const {
        return std::strcmp(title, bk.title) == 0;
    }
};

class Author {
private:
    char *name;
    std::list<Book> books;
    std::ostream& printAuthor(std::ostream&) const;
    friend std::ostream&operator<< (std::ostream& out, const Author& ar) {
        return ar.printAuthor(out);
    }
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
    friend class CheckedOutBook;
    friend Patron;
public:
    Author() {

    }
    bool operator== (const Author& ar) const {
        return std::strcmp(name, ar.name) == 0;
    }
};

class CheckedOutBook {
private:
    std::list<Author>::iterator author;
    std::list<Book>::iterator book;
    friend void checkOutBook();
    friend void returnBook();
    friend Patron;
public:
    CheckedOutBook(std::list<Author>::iterator ar, std::list<Book>::iterator bk) {
        author = ar;
        book = bk;
    }
    bool operator== (const CheckedOutBook& bk) const {
        return std::strcmp(author->name, bk.author->name) == 0 &&
               std::strcmp(book->title, bk.book->title);
    }
};





#endif //CPPLEARN_LIBRARY_H
