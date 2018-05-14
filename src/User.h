/*
 * User.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef USER_H_
#define USER_H_

#include "string.h"

class User {
protected:
	int _id;
	unsigned int isTempPass;
	char *email, *password, *firstName, *lastName, *position;
public:
	User();
	virtual ~User();
	int getId();
	char* getEmail();
	char* getPassword();
	void setPassword(char*);
	char* getFirstName();
	void setFirstName(char*);
	char* getLastName();
	void setLastName(char*);
	char* getPosition();
};


User::User() {
	// TODO Auto-generated constructor stub

}

User::~User() {
	// TODO Auto-generated destructor stub
}

int User::getId() {
	return _id;
}

char* User::getEmail() {
	return email;
}

char* User::getPassword() {
	return password;
}

void User::setPassword(char* pass) {
	isTempPass = false;
	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
}

char* User::getFirstName() {
	return firstName;
}

void User::setFirstName(char* newFirstName) {
	firstName = new char[strlen(newFirstName) + 1];
	strcpy(firstName, newFirstName);
}

char* User::getLastName() {
	return lastName;
}

void User::setLastName(char* newLastName) {
	lastName = new char[strlen(newLastName) + 1];
	strcpy(lastName, newLastName);
}

char* User::getPosition() {
	return position;
}

#endif /* USER_H_ */
