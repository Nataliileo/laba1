#include "Fantastic.h"

#include <fstream>

using namespace std;

Fantastic::Fantastic(const string &fio, int bornYear, int dieYear, string *books, int bookSize, bool haveFilms) : Base(fio, bornYear,
                                                                                                         dieYear,
                                                                                                         books, bookSize),
                                                                                                    haveFilms(
                                                                                                            haveFilms) {}

void Fantastic::write(ofstream &fo) {
    fo << "Fantastic" << endl;
    fo << this->fio << endl;
    fo << this->bornYear << " " << this->dieYear << endl;
    fo << this->bookSize << endl;
    for (int i = 0; i < this->bookSize; ++i) {
        fo << this->books[i] << " ";
    }
    fo << endl;
    fo << this->haveFilms << endl;
}

ostream &operator<<(ostream &fo, const Fantastic &f) {
    fo << f.fio << endl;
    fo << f.bornYear << " " << f.dieYear << endl;
    fo << f.bookSize << endl;
    for (int i = 0; i < f.bookSize; ++i) {
        fo << f.books[i] << " ";
    }
    fo << endl;
    fo << "Have films: " << (f.haveFilms ? "yes" : "no") << endl;
    return fo;
}

void Fantastic::printToDisp() {
    cout << *this;
}

