/*
 * Team.h
 *
 *  Created on: May 8, 2018
 *      Author: mark
 */

#ifndef TEAM_H_
#define TEAM_H_

class Team {
private:
	int _id, teamId, teamLeadId;
public:
	Team();
	virtual ~Team();

	int getId();

	bool isTeamMember(int);
	bool isTeamLeader(int);
};

#endif /* TEAM_H_ */
