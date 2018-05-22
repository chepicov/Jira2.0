/*
 * Project.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef PROJECT_H_
#define PROJECT_H_

class Project {
private:
    int id;
    string name;
    bool isArchieved;
public:
    void setIsArchieved(bool);
    bool isIsArchieved() const;

    Project(string);
    Project();
    virtual ~Project();

    int getId() const;
    const string &getName() const;

    friend ostream &operator<<(ostream &, const Project);
};

int Project::getId() const {
    return id;
}

Project::Project() {}

Project::Project(string name) {
    int projectId = (rand() % 1000000) % (rand() % 123456);
    Project::id = projectId;
    Project::name = name;
}

Project::~Project() {}

const string &Project::getName() const {
    return name;
}

ostream &operator<<(ostream &out, const Project obj) {
    string status = obj.isIsArchieved() ? "archieved" : "active";
    out << obj.name << endl;
    return out;
}

bool Project::isIsArchieved() const {
    return isArchieved;
}

void Project::setIsArchieved(bool isArchieved) {
    Project::isArchieved = isArchieved;
}

#endif /* PROJECT_H_ */
