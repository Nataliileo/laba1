#include <iostream>
#include <fstream>
#include <sstream>

#include "Keeper.h"
#include "Romantic.h"
#include "Fantastic.h"
#include "Poets.h"

using namespace std;

const string filename = "text.txt";

int main() {
    setlocale(LC_ALL, "Russian");
    auto *k = new Keeper();
    bool fl = true;
    int mode;
    while (fl) {
        // read menu data
        cout << "0 - Прочитать из файла text.txt" << endl;
        cout << "1 - Добавить нового писателя" << endl;
        cout << "2 - записать в файл" << endl;
        cout << "3 - удалить писателя" << endl;
        cout << "4 - вывести всех писателей на экран" << endl;
        cout << "5 - выход" << endl;
        cin >> mode;
        if (mode == 0) {
			try {
				ifstream file;
				file.open(filename);
				int count;
				file >> count;
				cout << "Прочитано: " << count << " писателей" << endl;
				for (int j = 0; j < count; ++j) {
					string mode;
					file >> mode;
					string fio, words;
					file.ignore();
					getline(file, fio);
					int born, die, bookSize;
					file >> born >> die;
					file >> bookSize;
					file.ignore();
					getline(file, words);
					auto *lines = new string[bookSize];
					istringstream iss(words);
					string s;
					for (int l = 0; l < bookSize; ++l) {
						getline(iss, s, ' ');
						lines[l] = s;
					}
					if (mode == "Romantic") {
						string bio;
						file.ignore();
						getline(file, bio);
						auto *r = new Romantic(fio, born, die, lines, bookSize, bio);
						k->add(*r);
					} else if (mode == "Poet") {
						auto *p = new Poets(fio, born, die, lines, bookSize);
						k->add(*p);
					} else if (mode == "Fantastic") {
						bool have;
						file >> have;
						auto *f = new Fantastic(fio, born, die, lines, bookSize, have);
						k->add(*f);
					}
				}
				file.close();
			} catch (exception e) {
				cout << "Невозможно считать из файла" << e.what();
			}

            // add new element to array
        } else if (mode == 1) {
            cout << "1 - Поет, 2 - Романтик, 3 - Фантастик" << endl;
            int type;
            cout << "Выберите тип" << endl;
            cin >> type;
            cout << "Введите ФИО" << endl;
            string fio;
            cin.ignore();
            getline(cin, fio);
            int born, die;
            cout << "укажите дату рождения и дату смерти" << endl;
            cin >> born >> die;
            int bookSize;
            cout << "Введите количество книг" << endl;
            cin >> bookSize;
            string *books = new string[bookSize];
            string s;
            for (int i = 0; i < bookSize; ++i) {
                cout << "Введите название книги" << endl;
                cin >> s;
                books[i] = s;
            }
            switch (type) {
                case 1: {
                    auto *p = new Poets(fio, born, die, books, bookSize);
                    k->add(*p);
                    break;
                }
                case 2: {
                    cout << "Введите короткую биографию" << endl;
                    string bio;
                    cin.ignore();
                    getline(cin, bio);
                    auto *r = new Romantic(fio, born, die, books, bookSize, bio);
                    k->add(*r);
                    break;
                }
                case 3: {
                    cout << "Введите если ли у него книги из фантастики? 1- да, 0 - нет" << endl;
                    bool have;
                    cin >> have;
                    auto *f = new Fantastic(fio, born, die, books, bookSize, have);
                    k->add(*f);
                    break;
                }
                default: {
                    cout << "Выбрано ничего ;(" << endl;
                    break;
                }
            }
            // write to file
        } else if (mode == 2) {
			try {
				k->writeToFile(filename);
			} catch (exception e) {
				cout << "Невозможно записать в файл" << e.what();
			}
            // remove element
        } else if (mode == 3) {
            int index;
            cin >> index;
            k->remove(index);
            // print
        } else if (mode == 4) {
            k->print();
            // exit
        } else if (mode == 5) {
            fl = false;
        }
    }
    return 0;
}

