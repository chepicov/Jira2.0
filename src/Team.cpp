/*
 * Team.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string.h"

#include "Team.h"

using namespace std;

Team::Team() {
	_id = (rand() % 1000000) % (rand() % 999999);
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

Team::~Team() {
	// TODO Auto-generated destructor stub
}

int Team::getId() {
	return _id;
}

bool isTeamMember(int employeeId) {

}

bool isTeamLeader(int employeeId) {

}
