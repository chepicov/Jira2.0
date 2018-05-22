/*
 * Employee.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee : public User {
private:
    int projectId;
    string position;
    string projectName;
    bool isTeamLeader;
    int finishedTaskNumber;
    double efficiency;
    bool isTempPass;
public:
    Employee();
    Employee(const Employee &);
    Employee(string, string, string, int, string, bool);

    virtual ~Employee() override;

    bool isIsTempPass() const;

    bool isIsTeamLeader() const;

    void setIsTeamLeader(bool isTeamLeader);

    void setProjectId(int projectId);

    string getPosition();

    int getProjectId() const;

    void setEfficiency(int, time_t);

    void finishSignUp(string);

    const string &getProjectName() const;

    void setProjectName(const string &projectName);

    friend ostream &operator<<(ostream &, const Employee);

};

Employee *currentEmployee;

Employee::Employee(const Employee &obj) : User(obj.id, obj.email, obj.password) {
    projectId = obj.projectId;
    position = obj.position;
    isTeamLeader = obj.isTeamLeader;
    finishedTaskNumber = obj.finishedTaskNumber;
    efficiency = obj.efficiency;
    isTempPass = obj.isTempPass;
}

string Employee::getPosition() {
    return position;
}

Employee::Employee() {}

Employee::~Employee() {}

Employee::Employee(string email, string password, string position, int projectId, string projectName, bool isTempPass)
        : User(email, password) {
    this->position = position;
    this->isTempPass = isTempPass;
    this->finishedTaskNumber = 0;
    this->efficiency = 0;
    this->projectId = projectId;
    this->projectName = projectName;
}

ostream &operator<<(ostream &out, const Employee obj) {
    string position = obj.position == "dev" ? "разработчик" : "тестировщик";
    out << obj.email << " " << obj.projectName << " " << position;
    if (obj.position == "dev") {
        cout << " " << obj.efficiency;
    }
    if (obj.isTeamLeader) {
        cout << " тимлид";
    }
    cout << endl;
    return out;
}

void Employee::setEfficiency(int difficulty, time_t hours) {
    cout << hours << " " << difficulty << endl;
    double efficiency = difficulty / hours;
    Employee::finishedTaskNumber++;
    Employee::efficiency = (Employee::efficiency + efficiency) / Employee::finishedTaskNumber;
    cout << Employee::finishedTaskNumber << " " << Employee::efficiency << endl;
}

void Employee::setProjectId(int projectId) {
    Employee::projectId = projectId;
}

void Employee::setIsTeamLeader(bool isTeamLeader) {
    Employee::isTeamLeader = isTeamLeader;
}

int Employee::getProjectId() const {
    return projectId;
}

bool Employee::isIsTeamLeader() const {
    return isTeamLeader;
}

bool Employee::isIsTempPass() const {
    return isTempPass;
}

void Employee::finishSignUp(string hash) {
    Employee::password = hash;
    Employee::isTempPass = false;
}

const string &Employee::getProjectName() const {
    return projectName;
}

void Employee::setProjectName(const string &projectName) {
    Employee::projectName = projectName;
}

#endif /* EMPLOYEE_H_ */
