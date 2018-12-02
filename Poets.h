#ifndef LAB1_23_POETS_H
#define LAB1_23_POETS_H


#include <ostream>
#include "Base.h"

class Poets : public Base {
public:
    void write(ofstream &fo) override;

    Poets(const string &fio, int bornYear, int dieYear, string *books, int bookSize);

    void printToDisp() override;

    friend ostream &operator<<(ostream &os, const Poets &poets);
};


#endif //LAB1_23_POETS_H
