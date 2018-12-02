#ifndef LAB1_23_ROMANTIC_H
#define LAB1_23_ROMANTIC_H


#include <ostream>
#include "Base.h"

class Romantic : public Base {

    string shortBiography;
public:
    Romantic(const string &fio, int bornYear, int dieYear, string *books, int booksSize, const string &shortBiography);

    void write(ofstream &fo) override;
    friend ostream &operator<<(ostream &os, const Romantic &romantic);

    void printToDisp() override;
};


#endif //LAB1_23_ROMANTIC_H
