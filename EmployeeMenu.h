/*
 * EmployeeMenu.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef EMPLOYEEMENU_H_
#define EMPLOYEEMENU_H_

#include "Task.h"
#include "FileService.h"

class EmployeeMenu {
public:
    EmployeeMenu();
    virtual ~EmployeeMenu();

    // Показать меню сотрудника
    static void showMenu();

    // Создать задачу
    static void createTask();
    // Присоединиться к задаче
    static void assignTask();
    // Переместить задачу
    static void moveTask();
    // Показать задачи
    static void showTasks();
    // Показать задачи текущего сотрудника
    static void showEmployeeTasks();

    // Завершить регистрацию сотрудника
    static void finishSignUp();
    // Обновить информацию о сотруднике в файле
    static void updateEmployee(int, int, time_t);
    static void updateEmployee(Employee);
};

EmployeeMenu::EmployeeMenu() {}

EmployeeMenu::~EmployeeMenu() {}

void EmployeeMenu::showMenu() {
    bool isCycled = true;
    if (currentEmployee->getProjectId() == 0) {
        while (true) {
            cout << "Вы не добавлены к проекту.\nПожалуйста, свяжитесь с администратором\n";
            cout << "'0' для выхода из учётной записи\n";
            int operation;
            cin >> operation;
            if (operation == 0) {
                break;
            }
        }
    }
    while (isCycled && currentEmployee->getProjectId() != 0) {
        int index = 1;
        cout << "Меню: " << endl;
        cout << index++ << ". Просмотреть задачи" << endl;
        cout << index++ << ". Просмотреть свои задачи" << endl;
        cout << index++ << ". Присоединиться к  задаче" << endl;
        cout << index++ << ". Переместить задачу" << endl;
        if (currentEmployee->isIsTeamLeader()) {
            cout << index++ << ". Создать задачу" << endl;
        }
        cout << "0. Выход из учётной записи" << endl;
        int operation;
        cin >> operation;
        switch (operation) {
            case 1:
                try {
                    showTasks();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 2:
                try {
                    showEmployeeTasks();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 3:
                try {
                    assignTask();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 4:
                try {
                    moveTask();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 5:
                if (index == 6) {
                    try {
                        createTask();
                    } catch (Exception&Obj) {
                        cout << Obj.what();
                    }
                } else {
                    cout << "Неверный ввод\n";
                }
                break;
            case 0:
                isCycled = false;
                break;
            default:
                cout << "Неверный ввод\n";
                break;
        }
    }
}

void EmployeeMenu::finishSignUp() {
    string newPass;
    string confirmPass;
    bool success = false;
    cout << "\nСмена пароля\n\n";
    while (!success) {
        cout << "Новый пароль: ";
        cin >> newPass;
        cout << "Подтвердите пароль: ";
        cin >> confirmPass;
        if (newPass.length() < 6) {
            cout << "Пароль слишком короткий\nПовторите попытку\n";
            continue;
        }
        if (newPass == confirmPass) {
            success = true;
        } else {
            cout << "Пароли не совпадают. Введите снова." << endl << endl;
        }
    }
    string hash = sha256(newPass);
    currentEmployee->finishSignUp(hash);
    updateEmployee(*currentEmployee);
    cout << "Данные сохранены." << endl;
}


void EmployeeMenu::createTask() {
    string name;
    int difficulty;

    cout << "Название задачи: ";
    cin >> name;
    cout << "Предполагаемая сложность в часах: ";
    cin >> difficulty;
    Task task(name, currentEmployee->getProjectId(), 0, difficulty);
    FileService::writeObject<Task>(task, "/Users/nasta/Desktop/tasks.txt");
    cout << "Задача создана\n";
}

void EmployeeMenu::showTasks() {
    Task obj;
    vector<Task> tasks[8];

    ifstream readFile("/Users/nasta/Desktop/tasks.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.getProjectId() == currentEmployee->getProjectId()) {
            tasks[obj.getStatus()].push_back(obj);
        }
    }
    readFile.close();

    for (int i = 0; i < 8; i++) {
        cout << endl << taskBoards[i] << endl;
        int index = 1;
        for (auto &&task:tasks[i]) {
            cout << index++ << ". " << task;
        }
    }
}

bool sortByDifficulty (Task i,Task j) { return (i.getDifficulty() < j.getDifficulty()); }
bool sortByName (Task i,Task j) { return (i.getName() < j.getName()); }

void EmployeeMenu::showEmployeeTasks() {
    Task obj;
    vector<Task> tasks;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/tasks.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.getProjectId() == currentEmployee->getProjectId()
            && (((currentEmployee->getPosition() == "dev") && (obj.getDevId() == currentEmployee->getId()))
                || ((currentEmployee->getPosition() == "tester") && (obj.getTesterId() == currentEmployee->getId())))) {
            cout << index++ << ". " << obj;
            tasks.push_back(obj);
        }
    }
    readFile.close();
    bool isCycled = true;
    cout << "\nВыберите команду:\n";
    while (isCycled) {
        cout << "1. Сортировать по сложности\n2. Сортировать по заголовку\n0. Выйти в главное меню\n";
        int option;
        cin >> option;
        switch (option) {
            case 0:
                isCycled = false;
                break;
            case 1:
                sort(tasks.begin(), tasks.end(), sortByDifficulty);
                cout << "Результат:\n";
                for (auto &&task:tasks) {
                    cout << task;
                }
                break;
            case 2:
                sort(tasks.begin(), tasks.end(), sortByName);
                cout << "Результат:\n";
                for (auto &&task:tasks) {
                    cout << task;
                }
                break;
            default:
                cout << "Неверный ввод\n";
                break;
        }
    }
}

void EmployeeMenu::assignTask() {
    vector<Task> tasks;
    vector<Task> projectTasks;
    Task obj;
    int index = 1;
    int taskIndex;

    ifstream readFile("/Users/nasta/Desktop/tasks.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.getProjectId() == currentEmployee->getProjectId()
            && (((currentEmployee->getPosition() == "dev") && (obj.getDevId() == 0) && (obj.getStatus() == 1))
                || ((currentEmployee->getPosition() == "tester") && (obj.getTesterId() == 0) && (obj.getStatus() == 4)))) {
            cout << index++ << ". " << obj;
            projectTasks.push_back(obj);
        }
        tasks.push_back(obj);
    }
    readFile.close();
    cout << "\nВыберите задачу (0 для отмены): " << endl;
    cin >> taskIndex;

    if (taskIndex == 0) {
        return;
    }
    if (taskIndex  > projectTasks.size()) {
        throw Exception("Неверный ввод\n");
    }

    FileService::clearFile("/Users/nasta/Desktop/tasks.txt");

    for (auto &&task:tasks) {
        if (task.getId() == projectTasks[taskIndex-1].getId()) {
            if (currentEmployee->getPosition() == "dev") {
                task.setDevId(currentEmployee->getId());
            } else {
                task.setTesterId(currentEmployee->getId());
            }
        }
        FileService::writeObject<Task>(task, "/Users/nasta/Desktop/tasks.txt");
    }
}

void EmployeeMenu::moveTask() {
    vector<Task> tasks;
    vector<Task> projectTasks;
    Task obj;
    int index = 1;
    int taskIndex;

    ifstream readFile("/Users/nasta/Desktop/tasks.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.getProjectId()  == currentEmployee->getProjectId()
            && (((currentEmployee->getPosition() == "dev") && (obj.getDevId() == currentEmployee->getId())
                 && ((obj.getStatus() > 0) && (obj.getStatus() < 4)))
                || ((currentEmployee->getPosition() == "tester") && (obj.getTesterId() == currentEmployee->getId())
                    && ((obj.getStatus() == 4) || (obj.getStatus() == 5)))
                || ((currentEmployee->isIsTeamLeader()) && ((obj.getStatus() == 0) || (obj.getStatus() == 6))))) {
            cout << index++ << ". " << obj;
            projectTasks.push_back(obj);
        }
        tasks.push_back(obj);
    }
    readFile.close();
    cout << "\nВыберите задачу (0 для отмены): " << endl;
    cin >> taskIndex;
    if (taskIndex == 0) {
        return;
    }
    if (taskIndex  > projectTasks.size()) {
        throw Exception("Неверный ввод\n");
    }
    int newStatus;
    int status = projectTasks[taskIndex-1].getStatus();
    cout << status << endl;
    switch (status) {
        case 5:
            if (currentEmployee->getPosition() == "tester") {
                cout << "1. В Reopened\n2. В Under Review\n";
                int option;
                cin >> option;
                switch (option) {
                    case 1:
                        newStatus = 2;
                        break;
                    case 2:
                        newStatus = 6;
                        break;
                }
            } else {
                cout << "Вы не можете переместить эту задачу.\n";
            }
            break;
        case 6:
            if (currentEmployee->isIsTeamLeader()) {
                cout << "1. В Reopened\n2. В Done\n";
                int option;
                cin >> option;
                switch (option) {
                    case 1:
                        newStatus = 2;
                        break;
                    case 2:
                        newStatus = 7;
                        break;
                }
            } else {
                cout << "Вы не можете переместить эту задачу.\n";
            }
            break;
        case 1:
            newStatus = status + 2;
            break;
        default:
            newStatus = status + 1;
            break;
    }


    FileService::clearFile("/Users/nasta/Desktop/tasks.txt");

    for (auto &&task:tasks) {
        if (task.getId() == projectTasks[taskIndex-1].getId()) {
            task.setStatus(newStatus);
            if (newStatus == 3) {
                time_t seconds;
                seconds = time(NULL);
                task.setStartedOn(seconds);
            }
            if (newStatus == 4) {
                time_t seconds = time(NULL) - task.getStartedOn();
                task.setTotalTime(seconds);
            }
            if (newStatus == 7) {
                updateEmployee(task.getDevId(), task.getDifficulty(), task.getTotalTime());
            }
            cout << "Задача перенесена в " << taskBoards[newStatus] << endl<<endl;
        }
        FileService::writeObject<Task>(task, "/Users/nasta/Desktop/tasks.txt");
    }
}

void EmployeeMenu::updateEmployee(int devId, int difficulty, time_t spentTime) {
    vector<Employee> employees;
    Employee obj;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        employees.push_back(obj);
    }

    FileService::clearFile("/Users/nasta/Desktop/employees.txt");
    for (auto &&employee:employees) {
        if (employee.getId() == devId) {
            employee.setEfficiency(difficulty, spentTime);
        }
        FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
    }
}

void EmployeeMenu::updateEmployee(Employee newEmployee) {
    vector<Employee> employees;
    Employee obj;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        employees.push_back(obj);
    }

    FileService::clearFile("/Users/nasta/Desktop/employees.txt");
    for (auto &&employee:employees) {
        if (employee.getId() == newEmployee.getId()) {
            FileService::writeObject<Employee>(newEmployee, "/Users/nasta/Desktop/employees.txt");
        } else {
            FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
        }
    }
}

#endif /* EMPLOYEEMENU_H_ */
