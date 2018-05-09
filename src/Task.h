/*
 * Task.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef TASK_H_
#define TASK_H_

class Task {
private:
	int status, _id, projectId, titleId, devId, testerId;
	char *startedOn, *deadLine;
public:
	Task();
	virtual ~Task();
	Task(int, char *, int, char *);

	void setStatus(int);
	void setDev(int);
	void setTester(int);

	int getId();
	int getProjectId();
	char *getTitle();
	int getDevId();
	int getTesterId();
	char *getStartDate();
	char *getDeadLine();
};

#endif /* TASK_H_ */
