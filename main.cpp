//============================================================================
// Name        : Jira2.cpp
// Author      : Mark
// Version     :
// Copyright   : Chepicov Mark
// Description : C++, Ansi-style
//============================================================================
#include <iostream>
#include "string"
#include "vector"
#include <typeinfo>
#include <ctime>
#include "fstream"

using namespace std;

#include "Exception.h"
#include "SHA256.h"
#include "User.h"
#include "Employee.h"
#include "Admin.h"
#include "Registration.h"
#include "Project.h"
#include "AdminMenu.h"
#include "EmployeeMenu.h"
#include "Login.h"

int main() {
    srand(time(0));
    int option;
    bool isCycled = true;

    while (isCycled) {
        bool isAdminExists = false;
        Admin obj;
        ifstream adminFile("/Users/nasta/Desktop/admins.txt");

        if (adminFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
            isAdminExists = true;
        }
        adminFile.close();
        if (!isAdminExists) {
            cout << "\n1. Регистрация администратора.\n0. Выход" << endl;
            cout << "Введите команду: ";
            cin >> option;

            switch (option) {
                case 1:
                    try {
                        Registration::registration();
                    } catch (...) {
                        cout << "Ошибка!";
                    }
                    break;
                case 0:
                    isCycled = false;
                    break;
                default:
                    cout << "\nТакого варианта нет" << endl;
                    break;
            }
        } else {
            try {
                Login::loginMenu();
            } catch (...) {
                cout << "Ошибка!";
            }
        }
    };
    return 0;
}
