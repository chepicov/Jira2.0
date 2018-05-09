/*
 * Employee.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "User.h"

class Employee: public User {
private:
	double efficiency;
public:
	Employee();
	virtual ~Employee();
	Employee(char*, char*, double);

	void showMenu();
	double getEfficiency();
	void setEfficiency(double);
	void createTask();
	void assignTaskDev();
	void assignTaskTest();
	int reviewTaskTest();
	int reviewTaskLead();
	void moveTask();
};

#endif /* EMPLOYEE_H_ */
