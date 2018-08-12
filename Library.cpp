//
// Created by xingc on 2018/8/10.
//

#include "Library.h"
std::list<Author> catalog['Z' + 1];//书籍的作者，以字母为索引
std::list<Patron> people['Z' + 1];//至少用过一次图书馆的人 以字母为索引
//需要注意

//const 类型的容器只能用 const_iterator
std::ostream& Author::printAuthor(std::ostream &out) const {
    out << name << std::endl;
    std::list<Book>::const_iterator ref = books.begin();
    for (; ref != books.end() ; ++ref) {
        out << *ref;
    }
    return out;
}

std::ostream& Book::printBook(std::ostream &out) const {
    out << " * " << std::endl;
    if (patron != 0){
        out << " - checked out to " << patron->name;
    }
    out << std::endl;
    return out;
}

std::ostream& Patron::printPatron(std::ostream &out) const {
    out << name ;
    if (!books.empty()) {
        out << " has the following books: \n";
        std::list<CheckedOutBook>::const_iterator bk = books.begin();
        for (; bk != books.end(); bk++) {
            out << " * " << bk->author->name << ", " << bk->book->title << std::endl;
        }
    } else
        out << " has no books \n" ;
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::list<T>& lst) {
    for (typename std::list<T>::const_iterator ref = lst.begin(); ref != lst.end(); ++ref) {
        out << *ref;
    }
    return std::cout;
}

char *getString(char *msg) {
    char s[82], i, *destin;
    std::cout << msg;
    std::cin.get(s, 80);
    while (std::cin.get(s[81]) && s[81] != '\n');
    destin = new char[std::strlen(s) + 1];
    for (int i = 0; destin[i] = toupper(s[i]); i++) {

    }
    return destin;
}

void status() {
    register int i;
    std::cout << "Library has the following books:\n\n";
    for (int j = 'A'; j < 'Z'; ++j) {
        if (!catalog[j].empty()){
            std::cout << catalog[j];
        }
    }
    std::cout << "\nThe following people are using the library:\n\n";
    for (int k = 'A'; k < 'Z'; ++k) {
        if (!people[k].empty()) {
            std::cout << people[k];
        }
    }
}

void includeBook() {
    Author newAuthor;
    Book newBook;
    newAuthor.name = getString("Enter author's name: ");
    newBook.title = getString("Enter the title of the book: ");
    std::list<Author>::iterator oldAuthor = find(catalog[newAuthor.name[0]].begin(), catalog[newAuthor.name[0]].end(), newAuthor);
    if (oldAuthor == catalog[newAuthor.name[0]].end()) {
        newAuthor.books.push_front(newBook);
    } else (*oldAuthor).books.push_front(newBook);
}

void checkOutBook() {
    Patron patron;
    Author author;
    Book book;
    std::list<Author>::iterator authorRef;
    std::list<Book>::iterator bookRef;
    patron.name = getString("Enter patron's name: ");
    while (true) {
        author.name = getString("Enter author's name");
        authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
        if (authorRef == catalog[author.name[0]].end()){
            std::cout << "Misspelled author's name\n";
        } else break;
    }
    while (true) {
        book.title = getString("Enter the title of the bool:");
        bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
        if (bookRef == (*authorRef).books.end()) {
            std::cout << "Misspelled titles\n";
        } else break;
    }
    std::list<Patron>::iterator patronRef;
    patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(), patron);
    CheckedOutBook checkedOutBook(authorRef, bookRef);
    if (patronRef == people[patron.name[0]].end()) {
        patron.books.push_front(checkedOutBook);
        people[patron.name[0]].push_front(patron);
        (*bookRef).patron = &*people[patron.name[0]].begin();
    }
    else {
        (*patronRef).books.push_front(checkedOutBook);
        (*bookRef).patron = &*patronRef;
    }
}

void returnBook() {
    Patron patron;
    Author author;
    Book book;
    std::list<Author>::iterator authorRef;
    std::list<Book>::iterator bookRef;
    std::list<Patron>::iterator patronRef;
    while (true) {
        patron.name = getString("Enter patron's name");
        patronRef = find(people[patron.name[0]].begin(), people[patron.name[0]].end(), patron);
        if (patronRef == people[patron.name[0]].end()) {
            std::cout << "Patron's name misspelled\n";
        }
        else break;
    }

    while (true) {
        author.name = getString("Enter author's name");
        authorRef = find(catalog[author.name[0]].begin(), catalog[author.name[0]].end(), author);
        if (authorRef == catalog[author.name[0]].end()){
            std::cout << "Misspelled author's name\n";
        }
        else break;
    }

    while (true) {
        book.title = getString("Enter the title of the bool:");
        bookRef = find((*authorRef).books.begin(), (*authorRef).books.end(), book);
        if (bookRef == (*authorRef).books.end()) {
            std::cout << "Misspelled titles\n";
        }
        else break;
    }

    CheckedOutBook checkedOutBook(authorRef, bookRef);
    (*bookRef).patron = 0;
    (*patronRef).books.remove(checkedOutBook);
}

int menu() {
    int option;
    std::cout << "\nEnter one of the following options:\n" << "1. Include a book in the catalog\n 2.Check out a book\n 3. Return a book\n 4. Status\n5. Exit\n" << "Your option?";
    std::cin >> option;
    std::cin.get();
    return option;
}