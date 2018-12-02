#include <fstream>

#include "Poets.h"


Poets::Poets(const string &fio, int bornYear, int dieYear, string *books, int bookSize) : Base(fio, bornYear, dieYear, books, bookSize) {}

ostream &operator<<(ostream &os, const Poets &poets) {
    os << poets.fio << endl;
    os << poets.bornYear << " " << poets.dieYear << endl;
    for (int i = 0; i < poets.getBookSize(); ++i) {
        cout << poets.books[i] << " ";
    }
    return os;
}

void Poets::write(ofstream &fo) {
    fo << "Poet" << endl;
    fo << this->fio << endl;
    fo << this->bornYear << " " << this->dieYear << endl;
    fo << this->bookSize << endl;
    for (int i = 0; i < this->bookSize; ++i) {
        fo << this->books[i] << " ";
    }
    fo << endl;
}

void Poets::printToDisp() {
    cout << *this;
}

