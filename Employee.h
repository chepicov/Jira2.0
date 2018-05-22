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
    int id;
    string email;
    int projectId;
    string password;
    string position;
    string projectName;
    bool isTeamLeader;
    int finishedTaskNumber;
    double efficiency;
    bool isTempPass;
public:
    Employee(const Employee &);

    bool isIsTempPass() const;

    bool isIsTeamLeader() const;

    void setIsTeamLeader(bool isTeamLeader);

    void setProjectId(int projectId);

    Employee();

    virtual ~Employee() override ;

    Employee(string, string, string, int, string, bool);

    string getPosition();

    string getEmail();

    string getPassword();

    int getId() const;

    int getProjectId() const;

    friend ostream &operator<<(ostream &, const Employee);

    friend istream &operator>>(istream &, Employee &);

    void setEfficiency(int, time_t);

    void finishSignUp(string);

    const string &getProjectName() const;

    void setProjectName(const string &projectName);

};

Employee *currentEmployee;

Employee::Employee(const Employee &obj) {
    id = obj.id;
    email = obj.email;
    projectId = obj.projectId;
    password = obj.password;
    position = obj.position;
    isTeamLeader = obj.isTeamLeader;
    finishedTaskNumber = obj.finishedTaskNumber;
    efficiency = obj.efficiency;
    isTempPass = obj.isTempPass;
}

string Employee::getPosition() {
    return position;
}

string Employee::getEmail() {
    return email;
}

string Employee::getPassword() {
    return password;
}

Employee::Employee() {}

Employee::~Employee() {}

Employee::Employee(string email, string password, string position, int projectId, string projectName, bool isTempPass) {
    int Id = (rand() % 1000000) % (rand() % 123456) + email.length();
    this->id = Id;
    this->position = position;
    this->email = email;
    this->password = password;
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

istream &operator>>(istream &in, Employee &obj) {
    cout << "Введите логин и пароль: ";
    in >> obj.email >> obj.password;
    return in;
}

int Employee::getId() const {
    return id;
}

void Employee::setEfficiency(int difficulty, time_t hours) {
    cout << hours << " " << difficulty << endl;
    double efficiency = (5 * 3600 * difficulty) / hours;
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
