/*
 * User.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef USER_H_
#define USER_H_

class User {
protected:
	int _id;
	unsigned int isTempPass;
	char *email, *password, *firstName, *lastName, *position;
public:
	User();
	User(char*, char*);
	virtual ~User();
	void login();
	void finishSignUp();
	int getId();
	char* getEmail();
	char* getPassword();
	char* setPassword(char*);
	char* getFirstName();
	char* setFirstName(char*);
	char* getLastName();
	char* setLastName(char*);
	char* getPosition();
};

#endif /* USER_H_ */
