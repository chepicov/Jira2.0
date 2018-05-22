/*
 * User.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef USER_H_
#define USER_H_

class User {
protected:
	int id;
	string email;
	string password;
public:
	User() {};
	virtual ~User(){};
	User(int, string, string);
	User(string, string);

	int getId() const;
	string getEmail();
	string getPassword();
};

User::User(int id, string email, string password) {
	this->id = id;
	this->email = email;
	this->password = password;
}

User::User(string email, string password) {
	int Id = (rand() % 1000000) % (rand() % 123456) + email.length();
	this->id = Id;
	this->email = email;
	this->password = password;
}

string User::getEmail() {
	return email;
}

string User::getPassword() {
	return password;
}

int User::getId() const {
	return id;
}

#endif /* USER_H_ */
