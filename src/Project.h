/*
 * Project.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef PROJECT_H_
#define PROJECT_H_

class Project {
private:
	int _id, teamId;
	unsigned int isArchieved;
	char *name;
public:
	Project();
	virtual ~Project();
	Project(char *);

	void archiveProject();

	int getId();
	int getTeamId();
	unsigned int getIsArchieved();
	char *getName();
};

#endif /* PROJECT_H_ */
