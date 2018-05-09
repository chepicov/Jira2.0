/*
 * Task.cpp
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#include "Task.h"

Task::Task() {
	// TODO Auto-generated constructor stub

}

Task::~Task() {
	// TODO Auto-generated destructor stub
}


Task::Task(int newProjectId, char * newTitle, int newStatus, char *newDeadLine) {
	projectId = newProjectId;
}

void Task::setStatus(int newStatus) {
	status = newStatus;
}
void Task::setDev(int dev) {
	devId = dev;
}
void Task::setTester(int tester) {
	testerId = tester;
}

int Task::getId() {
	return _id;
}

int Task::getProjectId() {
	return projectId;
}

char *Task::getTitle() {

}

int Task::getDevId() {
	return devId;
}

int Task::getTesterId() {
	return devId;
}

char *Task::getStartDate() {
	return startedOn;
}

char *Task::getDeadLine() {
	return deadLine;
}
