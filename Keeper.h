#ifndef LAB1_23_KEEPER_H
#define LAB1_23_KEEPER_H


#include <ostream>
#include "Base.h"

class Keeper {
public:
private:
    Base **data;
    int size;
public:
    Keeper();
    Keeper &add(Base &b);
    Keeper &remove(int index);
    Keeper &print();
    Keeper &writeToFile(string filename);

public:

    Base **getData() const;
    int getSize() const;

};


#endif //LAB1_23_KEEPER_H
