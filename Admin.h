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
public:
    Admin();
    virtual ~Admin();
    Admin(string, string);
    Admin(const Admin &);

    friend ostream &operator<<(ostream &, const Admin);
};

Admin::Admin() {}

Admin::~Admin() {}

Admin::Admin(const Admin &obj) : User(obj.id, obj.email, obj.password) {}

Admin::Admin(string email, string password) : User(email, password) {}

ostream &operator<<(ostream &out, const Admin obj) {
    out << obj.email << " " << obj.password << endl;
    return out;
}


#endif /* ADMIN_H_ */
