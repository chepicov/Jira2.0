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
	void login(int);
	void finishSignUp();
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

#endif /* USER_H_ */
