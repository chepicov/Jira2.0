/*
 * Admin.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef ADMIN_H_
#define ADMIN_H_

class Admin {
private:
    string login;
    string password;
    string role;
public:
	Admin();
	virtual ~Admin();
	Admin(char*, char*);
    Admin();
    Admin(string, string);
    Admin(const Admin &);
    ~Admin() override;

    void setLogin(const string &);
    void setPassword(const string &);
    void setRole(const string &);

    string getRole();
    string getLogin();
    string getPassword();

    friend ostream &operator<<(ostream &, const Admin);
    friend istream &operator>>(istream &, Admin &);

};

string Admin::getRole() {
    return role;
}

string Admin::getLogin() {
    return login;
}

string Admin::getPassword() {
    return password;
}

void Admin::setLogin(const string &login) {
    Admin::login = login;
}

void Admin::setPassword(const string &password) {
    Admin::password = password;
}

void Admin::setRole(const string &role) {
    Admin::role = role;
}

Admin::Admin() {}

Admin::~Admin() {}

Admin::Admin(const Admin &obj) {
    login = obj.login;
    password = obj.password;
    role = obj.role;
}

Admin::Admin(string login, string password) {
    this->role = "admin";
    this->login = login;
    this->password = password;
}

ostream &operator<<(ostream &out, const Admin obj) {
    out << "<" << obj.login << ">";
    return out;
}

istream &operator>>(istream &in, Admin &obj) {
    cout << "Введите логин и пароль: ";
    in >> obj.login >> obj.password;
    return in;
}


#endif /* ADMIN_H_ */
