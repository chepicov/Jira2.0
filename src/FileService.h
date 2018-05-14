/*
 * FileService.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef FILESERVICE_H_
#define FILESERVICE_H_

#include <string>
#include "iostream"
#include "string"
#include "fstream"
#include "Stack.h"

using namespace std;

class FileService {
public:
    template<typename T>
    static void readObjects(string);
    template<typename T>
    static void writeObject(T &, string);
    template<typename T>
    static void readService(string);
    template<typename T>
    static void fillAccounts(Stack<T> &, string);
    static void clearFile(string);
};


using namespace std;

template<typename T>
void FileService::fillAccounts(Stack<T> &account, string fileURL) {
    T o("a", "a");

    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        account.push(o);
    }
    readFile.close();
}

template<typename T>
void FileService::readObjects(string fileURL) {
    T o;
    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        cout << o;
    }
    readFile.close();
}

template<typename T>
void FileService::readService(string fileURL) {
    T o;
    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&o), sizeof(o))) {
        o.output();
    }
    readFile.close();
}

template<typename T>
void FileService::writeObject(T &o, string fileURL) {
    ifstream in(fileURL);
    std::ofstream ofs(fileURL, ios::out | ios::app);
    ofs.write(reinterpret_cast<char *>(&o), sizeof(o));
    ofs.close();
}

void FileService::clearFile(string fileURL) {
    std::ofstream ofs;
    ofs.open("/Users/vadimsukach/Desktop/admins.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

#endif /* FILESERVICE_H_ */
