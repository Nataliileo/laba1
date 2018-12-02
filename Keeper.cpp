#include <fstream>
#include "Keeper.h"

Base **Keeper::getData() const {
    return data;
}

int Keeper::getSize() const {
    return size;
}

Keeper::Keeper() {
    this->size = 0;
    this->data = nullptr;
}

Keeper &Keeper::add(Base &b) {
    this->size++;
    auto **copy = new Base*[this->size - 1];
    for (int i = 0; i < this->size - 1; ++i) {
        copy[i] = this->data[i];
    }
    this->data = new Base*[this->size];
    for (int j = 0; j < this->size; ++j) {
        this->data[j] = copy[j];
    }
    this->data[this->size - 1] = &b;
    return *this;
}

Keeper &Keeper::remove(int index) {
    if ((index >= this->size) || (index < 0)) {
        cout << "Error remove element" << endl;
    } else {
        auto **copy = new Base*[this->size];
        for (int i = 0; i < this->size; ++i) {
            copy[i] = this->data[i];
        }
        this->size--;
        this->data = new Base*[this->size];
        int k = 0;
        for (int i = 0; i < this->size + 1; ++i) {
            if (i == index) {
                continue;
            }
            this->data[k] = copy[i];
            k++;
        }

        delete []copy;
    }
    return *this;
}

Keeper &Keeper::print() {
    for (int i = 0; i < this->size; ++i) {
//        cout << *this->data[i] << endl;
        this->data[i]->printToDisp();
        cout << endl << endl;
    }
    return *this;
}

Keeper &Keeper::writeToFile(string filename) {
    ofstream file;
    file.open(filename);
    file << this->size << endl;
    for (int i = 0; i < this->size; ++i) {
        this->data[i]->write(file);
    }
    file.close();
    return *this;
}



