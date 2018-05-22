/*
 * FileService.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef FILESERVICE_H_
#define FILESERVICE_H_

class FileService {
public:
    template<typename T>
    static void readObjects(string);
    template<typename T>
    static void writeObject(T &, string);
    static void clearFile(string);
};

template<typename T>
void FileService::readObjects(string fileURL) {
    T obj;
    int index = 1;

    ifstream readFile(fileURL);
    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        cout <<index<<". "<< obj;
        index++;
    }
    readFile.close();
}


template<typename T>
void FileService::writeObject(T &obj, string fileURL) {
    ifstream in(fileURL);
    ofstream ofs(fileURL, ios::out | ios::app);
    ofs.write(reinterpret_cast<char *>(&obj), sizeof(obj));
    ofs.close();
}

void FileService::clearFile(string fileURL) {
    ofstream ofs;
    ofs.open(fileURL, ofstream::out | ofstream::trunc);
    ofs.close();
}

#endif /* FILESERVICE_H_ */
