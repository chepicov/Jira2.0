/*
 * Registration.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "regex"
#include "FileService.h"

using namespace std;

class Registration {
public:
    // Регистрация нового администратора
    static void registration();
};

void Registration::registration() {
    string email;
    string password;
    string passwordConfirm;
    bool isCycled = true;
    regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    cout << "\nРегистрация администратора" << endl;
    while (isCycled) {
        cout << "Введите email: ";

        cin >> email;

        if (!regex_match(email, emailRegex)) {
            cout << "Неверный email\n";
        } else {
            isCycled = false;
        }
    }
    isCycled = true;
    while (isCycled) {
        cout << "Введите пароль: ";
        cin >> password;
        cout << "Подтвердите пароль: ";
        cin >> passwordConfirm;

        if (password == passwordConfirm) {
            string hashedPassword = sha256(password);
            cout << hashedPassword;

            Admin newAdmin(email, hashedPassword);

            FileService::writeObject<Admin>(newAdmin, "/Users/nasta/Desktop/admins.txt");
            cout << " \nАккаунт создан\n";
            isCycled = false;
        } else {
            cout << "Пароли не совпадают\n";
        }
    }
}

#endif //REGISTRATION_H
