#include <fstream>
#include "Romantic.h"

Romantic::Romantic(const string &fio, int bornYear, int dieYear, string *books, int booksSize, const string &shortBiography) : Base(
        fio, bornYear, dieYear, books, booksSize), shortBiography(shortBiography) {}

void Romantic::write(ofstream &fo) {
    fo << "Romantic" << endl;
    fo << this->fio << endl;
    fo << this->bornYear << " " << this->dieYear << endl;
    fo << this->bookSize << endl;
    for (int i = 0; i < this->bookSize; ++i) {
        fo << this->books[i] << " ";
    }
    fo << endl;
    fo << this->shortBiography << endl;
}

ostream &operator<<(ostream &fo, const Romantic &r) {
    fo << r.fio << endl;
    fo << r.bornYear << " " << r.dieYear << endl;
    fo << r.bookSize << endl;
    for (int i = 0; i < r.bookSize; ++i) {
        fo << r.books[i] << " ";
    }
    fo << endl;
    fo << r.shortBiography << endl;
    return fo;
}

void Romantic::printToDisp() {
    cout << *this;
}


