#ifndef LAB1_23_BASE_H
#define LAB1_23_BASE_H

#include <iostream>

using namespace std;


class Base {
public:
    string fio;
    int bornYear, dieYear;
    string *books;
    int bookSize;

    int getBookSize() const;

    Base(const string &fio, int bornYear, int dieYear, string *books, int booksSize);

    friend ostream &operator<<(ostream &os, const Base &base);

    virtual void write(ofstream &fo) = 0;
    virtual void printToDisp() = 0;
};


#endif //LAB1_23_BASE_H
