/*
 * Employee.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#include "Employee.h"
#include <iostream>
#include "string.h"

using namespace std;

Employee::Employee() {
	// TODO Auto-generated constructor stub

}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

Employee::Employee(char* email, char* position, double newEfficiency): User(email, position) {
	efficiency = newEfficiency;
};

void Employee::showMenu() {
	cout << "Меню: " << endl;
	cout << "1. Просмотреть задачи" << endl;
	cout << "2. Присоединиться к задаче" << endl;
	cout << "3. Переместить задачу" << endl;
	cout << "4. Создать задачу" << endl;
	cout << "5. Проверить задачу" << endl;
	int operation;
	switch (operation) {
	case 1:
		createTask();
		break;
	case 2:
		if (strcmp(position, "dev") == 0) {
			assignTaskDev();
		} else {
			assignTaskTest();
		}
		break;
	case 3:
		moveTask();
		break;
	case 4:
		createTask();
		break;
	default:
		if (strcmp(position, "tester") == 0) {
			reviewTaskTest();
		} else {
			reviewTaskLead();
		}
		break;
	}
}

void Employee::setEfficiency(double newEfficiency) {
	this->efficiency = newEfficiency;
}

double Employee::getEfficiency() {
	return this->efficiency;
}

void Employee::createTask() {
	cout << "";
}

void Employee::assignTaskDev() {
	int taskId;
	cout << "id";
	cin >> taskId;
}

void Employee::assignTaskTest() {

}

int Employee::reviewTaskTest() {

}

int Employee::reviewTaskLead() {

}

void Employee::moveTask() {

}
