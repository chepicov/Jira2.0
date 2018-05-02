#include <iostream>
#include "sha256.h"
 
using std::string;
using std::cout;
using std::endl;

template<class Type>
class ForFile {
    char *filename;
    fstream stream;
    public:
        //Конструктор с параметром
        ForFile<Type>(char *fln) {
            filename = new char[strlen(fln) + 1];
            strcpy(filename, fln);
        }
        //Деструктор
        ~ForFile<Type>() {
            delete[] filename;
            stream.close();
        }
        //Функция открытия файла для записи
        int open_save() {
            stream.close();
            stream.open(filename, ios::out | ios::trunc | ios::binary | ios::_Nocreate);
            if (stream.is_open() == false)
                throw excep_file("2003", "Error opening binary file to save data!");
            else
                return 0;
        }
        //Функция открытия файла для чтения
        int open_load() {
            stream.close();
            stream.open(filename, ios::in | ios::app | ios::binary | ios::_Nocreate);
            if (stream.is_open() == false)
                throw excep_file("2004", "Error opening binary file to save data!");
            else
                return 0;
        }
        //Функция переноса позиции в файле на начало
        void remote() {
            stream.seekg(0, ios_base::beg);
            stream.seekp(0, ios_base::beg);
            stream.clear();
        }
        //Функция чтения данных из файла
        int load(Type &data) {
            stream >> data;
            if (!stream.eof())
                return 1;
            else return 0;
        }
        //Функция сохранения данных в файл
        void save(Type &data) {
            stream.seekp(0, ios_base::beg);
            stream << data;
            stream.flush();
        }
};
 
int main(int argc, char *argv[])
{
    string input = "grape1";
    string output1 = sha256(input);
 
    cout << "sha256('"<< input << "'):" << output1 << endl;
    return 0;
}
