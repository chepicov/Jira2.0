/*
 * Admin.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#include <stdio.h>
#include <iostream>
#include "string.h"
#include "Admin.h"
#include "Project.h"
#include "Employee.h"

using namespace std;

Admin::Admin() {
	// TODO Auto-generated constructor stub

}


Admin::~Admin() {
	// TODO Auto-generated destructor stub
}

Admin::Admin(char* email, char* position): User(email, position) {};

void Admin::showMenu() {
	cout << "Меню: " << endl;
	cout << "1. Добавить сотрудника" << endl;
	cout << "2. Удалить сотрудника" << endl;
	cout << "3. Добавить проект" << endl;
	cout << "4. Удалить проект" << endl;
	cout << "5. Редактировать команду" << endl;
	int operation;
	switch (operation) {
	case 1:
		addEmployee();
		break;
	case 2:
		removeEmployee();
		break;
	case 3:
		createProject();
		break;
	case 4:
		archieveProject();
		break;
	default:
		editTeam();
		break;
	}
}

void Admin::createProject() {
	char *name = new char[255];
	cout << "Название проекта: ";
	cin >> name;
	new Project(name);
}

void Admin::archieveProject() {
	int projectId;
	cout << "" << endl;
	cin >> projectId;
}

void Admin::addEmployee() {
	cout << "" << endl;
	char *email = new char[255];
	cin >> email;
	cout << "" << endl;
	char *position = new char[255];
	cin >> position;
	new Employee(email, position, 0);
}

void Admin::removeEmployee() {
	cout << "" << endl;
	int employeeId;
	cin >> employeeId;
}

void Admin::editTeam() {
	cout << "" <<endl;
	int projectId;
	cin >> projectId;
}
