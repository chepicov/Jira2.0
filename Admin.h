/*
 * Admin.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include "User.h"

class Admin: public User {
private:
    int id;
    string email;
    string password;
public:
    int getId() const;
    Admin();
    virtual ~Admin();
    Admin(string, string);
    Admin(const Admin &);

    string getEmail();
    string getPassword();

    friend ostream &operator<<(ostream &, const Admin);
    friend istream &operator>>(istream &, Admin &);
};


string Admin::getEmail() {
    return email;
}

string Admin::getPassword() {
    return password;
}

Admin::Admin() {}

Admin::~Admin() {}

Admin::Admin(const Admin &obj) {
    email = obj.email;
    password = obj.password;
}

Admin::Admin(string email, string password) {
    this->id = (rand() % 1000000) % (rand() % 123456) + email.length();
    this->email = email;
    this->password = password;
}

ostream &operator<<(ostream &out, const Admin obj) {
    out << obj.email << " " << obj.password<<endl;
    return out;
}

istream &operator>>(istream &in, Admin &obj) {
    cout << "Введите логин и пароль: ";
    in >> obj.email >> obj.password;
    return in;
}

int Admin::getId() const {
    return id;
}


#endif /* ADMIN_H_ */
