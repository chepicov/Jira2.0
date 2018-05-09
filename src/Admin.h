/*
 * Admin.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include "User.h"

class Admin: public User {
public:
	Admin();
	Admin(char*, char*);
	virtual ~Admin();

	void showMenu();
	void createProject();
	void archieveProject();
	void addEmployee();
	void removeEmployee();
	void editTeam();
};

#endif /* ADMIN_H_ */
