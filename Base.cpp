#include "Base.h"

Base::Base(const string &fio, int bornYear, int dieYear, string *books, int booksSize) : fio(fio), bornYear(bornYear),
                                                                          dieYear(dieYear), books(books),
                                                                          bookSize(booksSize) {}

int Base::getBookSize() const {
    return bookSize;
}

ostream &operator<<(ostream &os, const Base &base) {
    os << "ФИО: " << base.fio << " родился: " << base.bornYear << " умер: " << base.dieYear << " книги: " << endl;
    for (int i = 0; i < base.bookSize; ++i) {
        os << base.books[i] << " ";
    }
    os << endl;
    return os;
}
