/*
 * Task.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef TASK_H
#define TASK_H

class Task {
private:
    int id;
    int projectId;
    int status;
    int devId;
    int testerId;
    string name;
    int difficulty;
    time_t startedOn;
    time_t totalTime;
public:
    Task();
    Task(string, int, int, int);

    int getDevId() const;
    int getTesterId() const;

    const string &getName() const;

    int getId() const;
    int getProjectId() const;

    void setDevId(int devId);

    void setTesterId(int testerId);

    void setStatus(int status);
    int getStatus() const;

    int getDifficulty() const;

    time_t getStartedOn() const;
    time_t getTotalTime() const;

    void setStartedOn(time_t startedOn);
    void setTotalTime(time_t totalTime);

    friend ostream &operator<<(ostream &, const Task);
};

string taskBoards[8] = {"Backlog", "To Do", "Reopened", "In Progress", "Ready to Test", "Testing", "Under Review", "Done"};
// 0. Backlog
// 1. To Do
// 2. Reopened
// 3. In Progress
// 4. Ready to Test
// 5. Testing
// 6. Under Review
// 7. Done

Task::Task() {}

Task::Task(string name, int projectId, int status, int difficulty) {
    Task::id = (rand() % 1000000) % (rand() % 123456);

    Task::name = name;
    Task::status = status;
    Task::projectId = projectId;
    Task::devId = 0;
    Task::testerId = 0;
    Task::totalTime = 0;
    Task::difficulty = difficulty;
}

int Task::getId() const {
    return id;
}

int Task::getProjectId() const {
    return projectId;
}

int Task::getStatus() const {
    return status;
}

const string &Task::getName() const {
    return name;
}

int Task::getTesterId() const {
    return testerId;
}

int Task::getDevId() const {
    return devId;
}

void Task::setDevId(int devId) {
    Task::devId = devId;
}

void Task::setTesterId(int testerId) {
    Task::testerId = testerId;
}

void Task::setStatus(int status) {
    Task::status = status;
}

int Task::getDifficulty() const {
    return difficulty;
}

ostream &operator<<(ostream &out, const Task obj) {
    out << obj.name << " " << taskBoards[obj.status] << " " << obj.difficulty << endl;
    return out;
}

time_t Task::getStartedOn() const {
    return startedOn;
}

void Task::setStartedOn(time_t startedOn) {
    Task::startedOn = startedOn;
}

time_t Task::getTotalTime() const {
    return totalTime;
}

void Task::setTotalTime(time_t totalTime) {
    Task::totalTime += totalTime;
}

#endif //TASK_H
