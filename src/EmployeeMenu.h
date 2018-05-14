/*
 * EmployeeMenu.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef EMPLOYEEMENU_H_
#define EMPLOYEEMENU_H_

class EmployeeMenu {
public:
	EmployeeMenu();
	virtual ~EmployeeMenu();

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

EmployeeMenu::EmployeeMenu() {
	// TODO Auto-generated constructor stub

}

EmployeeMenu::~EmployeeMenu() {
	// TODO Auto-generated destructor stub
}


void EmployeeMenu::showMenu() {
	cout << "Меню: " << endl;
	cout << "1. Просмотреть задачи" << endl;
	cout << "2. Присоединиться к задаче" << endl;
	cout << "3. Переместить задачу" << endl;
	cout << "4. Создать задачу" << endl;
	cout << "5. Проверить задачу" << endl;
	int operation;
	cin >> operation;
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


void EmployeeMenu::login() {
	char *login = new char[255], *pass = new char[255];
	bool success = false;
	while (!success) {
		cout << "Вход" << endl;
		cout << "Введите email: ";
		cin >> login;
		cout << "Введите пароль: ";
		cin >> pass;
		char *hash = new char[255];
		hash = sha256(pass);

		if ((strcmp(login, email) == 0) && (strcmp(password, hash) == 0)) {
			cout << "Вы вошли!" << endl << endl;
			success = true;
			if (isTempPass) {
				finishSignUp();
			}
		} else {
			cout << "Email и(или) пароль введены неверно. Попробуйте снова." << endl << endl;
		}
	}
}


void EmployeeMenu::finishSignUp() {
	char *newPass = new char[255];
	char *confirmPass = new char[255];
	bool success = false;
	while (!success) {
		cout << "Новый пароль: ";
		cin >> newPass;
		cout << "Подтвердите пароль: ";
		cin >> confirmPass;
		if (strcmp(newPass, confirmPass) == 0) {
			success = true;
		} else {
			cout << "Пароли не совпадают. Введите снова." << endl << endl;
		}
	}
	char *hash = new char[255];
	hash = sha256(newPass);
	password = new char[strlen(hash) + 1];
	strcpy(password, hash);
	isTempPass = false;
	cout << "Новый пароль добавлен." << endl;
}

void EmployeeMenu::setEfficiency(double newEfficiency) {
	this->efficiency = newEfficiency;
}

double EmployeeMenu::getEfficiency() {
	return this->efficiency;
}

void EmployeeMenu::createTask() {
	cout << "";
}

void EmployeeMenu::assignTaskDev() {
	int taskId;
	cout << "id";
	cin >> taskId;
}

void EmployeeMenu::assignTaskTest() {

}

int EmployeeMenu::reviewTaskTest() {

}

int EmployeeMenu::reviewTaskLead() {

}

void EmployeeMenu::moveTask() {

}

#endif /* EMPLOYEEMENU_H_ */
