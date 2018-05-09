/*
 * User.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */
#include <stdio.h>
#include <iostream>
#include "string.h"
#include <ctime>
#include <cstdlib>

#include "SHA256.h"
#include "User.h"

using namespace std;

static const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

User::User() {
	// TODO Auto-generated constructor stub
	_id = isTempPass = 0;
	email = position = password = firstName = lastName = NULL;
}

User::User(char* newEmail, char* newPosition) {
    _id = (rand() % 1000000) % (rand() % 1234568) + strlen(newEmail);
	email = new char[strlen(newEmail) + 1];
	strcpy(email, newEmail);

	position = new char[strlen(newPosition) + 1];
	strcpy(position, newPosition);

	isTempPass = true;
	char *tempPass = new char[6];
	for(unsigned int i = 0; i < 6; ++i) {
		tempPass[i] = alphanum[rand() % stringLength];
	}
	cout << "Temporary password of new user: " << tempPass << endl;
	cout << "Do not lose it!" << endl << endl;
	char *hash = new char[255];
	hash = sha256(tempPass);
	password = new char[strlen(hash) + 1];
	strcpy(password, hash);
}

User::~User() {
	// TODO Auto-generated destructor stub
}

void User::login() {
	char *login = new char[255], *pass = new char[255];
	bool success = false;
	while (!success) {
		cout << "Enter email: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> pass;
		char *hash = new char[255];
		hash = sha256(pass);
		if ((strcmp(login, email) == 0) && (strcmp(password, hash) == 0)) {
			cout << "You're in!" << endl << endl;
			success = true;
			if (isTempPass) {
				User::finishSignUp();
			}
		} else {
			cout << "Email and (or) password are incorrect. Try again please." << endl << endl;
		}
	}
}

void User::finishSignUp() {
	char *newPass = new char[255];
	char *confirmPass = new char[255];
	bool success = false;
	while (!success) {
		cout << "New password: ";
		cin >> newPass;
		cout << "Confirm password: ";
		cin >> confirmPass;
		if (strcmp(newPass, confirmPass) == 0) {
			success = true;
		} else {
			cout << "Passwords are not same. Try again please" << endl << endl;
		}
	}
	char *hash = new char[255];
	hash = sha256(newPass);
	password = new char[strlen(hash) + 1];
	strcpy(password, hash);
	isTempPass = false;
	cout << "New password has been added." << endl;
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

char* User::setPassword(char* pass) {
	isTempPass = false;
	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
}

char* User::getFirstName() {
	return firstName;
}

char* User::setFirstName(char* newFirstName) {
	firstName = new char[strlen(newFirstName) + 1];
	strcpy(firstName, newFirstName);
}

char* User::getLastName() {
	return lastName;
}

char* User::setLastName(char* newLastName) {
	lastName = new char[strlen(newLastName) + 1];
	strcpy(lastName, newLastName);
}

char* User::getPosition() {
	return position;
}
