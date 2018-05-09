/*
 * Project.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string.h"

#include "Project.h"
#include "Team.h"

using namespace std;

Project::Project() {
	// TODO Auto-generated constructor stub

}

Project::~Project() {
	// TODO Auto-generated destructor stub
}

Project::Project(char *projectName) {
	_id = ((rand() % 1000000) % (rand() % 1234568)) + strlen(projectName);
    if (name) delete[]name;
	name = new char[strlen(projectName) + 1];
	strcpy(name, projectName);
	Team *team = new Team();
	teamId = team->getId();
	cout << "Проект '" << name << "' успешно создан." << endl;
}
