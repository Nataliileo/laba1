#ifndef LAB1_23_FANTASTIC_H
#define LAB1_23_FANTASTIC_H


#include <ostream>
#include "Base.h"

class Fantastic : public Base {

    bool haveFilms;

public:
    Fantastic(const string &fio, int bornYear, int dieYear, string *books, int bookSize, bool haveFilms);

    void write(ofstream &fo) override;

    void printToDisp() override;

    friend ostream &operator<<(ostream &os, const Fantastic &fantastic);
};


#endif //LAB1_23_FANTASTIC_H
