//
// Created by xingc on 2018/8/10.
//

#ifndef CPPLEARN_LIBRARY_H
#define CPPLEARN_LIBRARY_H

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

class Patron {
private:
    char *name;
    std::list<CheckedOutBook> books;
    std::ostream& printPatron(std::ostream&) const;
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

std::list<Author> catalog['Z' + 1];
std::list<Patron> people['Z' + 1];



#endif //CPPLEARN_LIBRARY_H
