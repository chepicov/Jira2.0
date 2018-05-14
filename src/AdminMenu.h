/*
 * AdminMenu.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef ADMINMENU_H_
#define ADMINMENU_H_

static const char alphanum[] = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

class AdminMenu {
public:
	virtual ~AdminMenu();
	void showAdminMenu();
	void createProject();
	void archieveProject();
	void addEmployee();
	void removeEmployee();
	void editTeam();
};

void AdminMenu::showAdminMenu() {
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

void AdminMenu::createProject() {
	char *name = new char[255];
	cout << "Название проекта: ";
	cin >> name;
	new Project(name);
}

void AdminMenu::createTeam() {
	_id = (rand() % 1000000) % (rand() % 123456);
	cout << "Введите номера сотрудников для добавления в команду ('Enter' для ввода)" << endl;
	char * teamMember = new char[255];
	int *teamMembers = new int[100];
	int i = 0;
	int id = 0;
	cin.ignore();
	while (strlen(teamMember) != 0 || i == 0) {
		id = atoi(teamMember);
		if (strlen(teamMember) > 0 && id > 0) {
			teamMembers[i++] = id;
			cout << "Сотрудник добавлен в команду" << endl;
		}
		if (strlen(teamMember) == 0 && i == 0) {
			cout << "Введите как минимум 1 сотрудника" << endl;
		} else if (id == 0) {
			cout << "Неверный ввод" << endl;
		}
		cin.getline(teamMember, 255);
	}
	cout << "Команда:";
	for (int j = 0; j < i; j++) {
		cout << " " << teamMembers[j];
	}
	cout << endl << "Пожалуйста, выберите тимлида из выбранных сотрудников: ";
	int teamLeader;
	cin >> teamLeader;
}

void AdminMenu::archieveProject() {
	int projectId;
	cout << "" << endl;
	cin >> projectId;
}


void AdminMenu::addEmployee() {
	cout << "Введите email сотрудника" << endl;
	char *newEmail = new char[255];
	cin >> newEmail;
	cout << "Введите должность" << endl;
	char *newPosition = new char[255];
	cin >> newPosition;

    _id = (rand() % 1000000) % (rand() % 123456) + strlen(newEmail);
	email = new char[strlen(newEmail) + 1];
	strcpy(email, newEmail);

	position = new char[strlen(newPosition) + 1];
	strcpy(position, newPosition);

	isTempPass = true;
	char *tempPass = new char[6];
	for(unsigned int i = 0; i < 6; ++i) {
		tempPass[i] = alphanum[rand() % stringLength];
	}
	cout << "Временный пароль нового пользователя: " << tempPass << endl;
	char *hash = new char[255];
	hash = sha256(tempPass);
	password = new char[strlen(hash) + 1];
	strcpy(password, hash);
}


void AdminMenu::login() {
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


void AdminMenu::removeEmployee() {
	cout << "" << endl;
	int employeeId;
	cin >> employeeId;
}

void AdminMenu::editTeam() {
	cout << "" <<endl;
	int projectId;
	cin >> projectId;
}

#endif /* ADMINMENU_H_ */
