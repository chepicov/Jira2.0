/*
 * AdminMenu.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */

#ifndef ADMINMENU_H_
#define ADMINMENU_H_

#include "FileService.h"
#include "regex"

static const string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int stringLength = alphanum.length() - 1;

class AdminMenu {
public:
    virtual ~AdminMenu();
    // Показать меню администратора
    static void showAdminMenu();

    // Создать проект
    static void createProject();
    // Архивировать проект
    static void archieveProject();
    // Показать проекты
    static void showProjects();
    // Показать архивированные проекты
    static void showArchievedProjects();

    // Добавить сотрудника
    static void addEmployee();
    // Удалить сотрудника
    static void removeEmployee();
    // Искать сотрудников
    static void findEmployee();
    // Показать сотрудников
    static void showEmployees();

    // Редактировать команду проекта
    static void editTeam();
};

void AdminMenu::showAdminMenu() {
    bool isCycled = true;
    while (isCycled) {
        cout << "Меню: " << endl;
        cout << "1. Просмотреть проекты" << endl;
        cout << "2. Просмотреть сотрудников" << endl;
        cout << "3. Найти сотрудника" << endl;
        cout << "4. Добавить сотрудника" << endl;
        cout << "5. Удалить сотрудника" << endl;
        cout << "6. Добавить проект" << endl;
        cout << "7. Архивировать проект" << endl;
        cout << "8. Редактировать команду" << endl;
        cout << "9. Просмотреть архивированные проекты" << endl;
        cout << "0. Выход из учётной записи" << endl;
        int operation;
        cin >> operation;
        switch (operation) {
            case 1:
                try {
                    showProjects();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 2:
                try {
                    showEmployees();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 3:
                try {
                    findEmployee();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 4:
                try {
                    addEmployee();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 5:
                try {
                    removeEmployee();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 6:
                try {
                    createProject();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 7:
                try {
                    archieveProject();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 8:
                try {
                    editTeam();
                } catch (Exception&Obj) {
                    cout << Obj.what();
                }
                break;
            case 9:
                try {
                    showArchievedProjects();
                } catch (Exception&Obj) {
                    cout << Obj.what();
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

void AdminMenu::createProject() {
    string name;
    int teamMemberIndex;
    bool isCycled = true;
    Project projectObj;
    vector<Project> projects;

    ifstream file("/Users/nasta/Desktop/projects.txt");

    while (file.read(reinterpret_cast<char *>(&projectObj), sizeof(projectObj))) {
        projects.push_back(projectObj);
    }
    while (isCycled) {
        cout << "Название проекта: ";
        cin >> name;
        int n = 0;
        for (auto &&project:projects) {
            if (project.getName() == name) {
                cout << "Проект с таким названием уже существует\nПовторите попытку\n";
                break;
            }
            n++;
        }
        if (n == projects.size()) {
            isCycled = false;
        }
    }
    Project project(name);
    FileService::writeObject<Project>(project, "/Users/nasta/Desktop/projects.txt");
    cout << "Проект " << project.getName() << " создан\n";
    Employee obj;
    int index = 1;
    vector<Employee> employees;
    vector<Employee> freeEmployees;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.getProjectId() == 0) {
            cout << index << ". " << obj;
            index++;
            freeEmployees.push_back(obj);
        }
        employees.push_back(obj);
    }
    readFile.close();

    if (freeEmployees.size() == 0) {
        return;
    }

    isCycled = true;
    while (isCycled) {
        cout << "Введите номера сотрудников для добавления в команду\n(Введите 0, чтобы закончить ввод): ";
        cin >> teamMemberIndex;
        if (teamMemberIndex == 0) {
            break;
        }
        if (freeEmployees[teamMemberIndex - 1].getProjectId() == project.getId()) {
            cout << "Сотрудник уже добавлен\n";
            break;
        }
        if (teamMemberIndex  > freeEmployees.size()) {
            cout << "Неверный ввод\n";
            break;
        }
        freeEmployees[teamMemberIndex - 1].setProjectId(project.getId());
        freeEmployees[teamMemberIndex - 1].setProjectName(project.getName());
    }

    cout << endl << "Пожалуйста, выберите тимлида из выбранных сотрудников (0 для отмены): ";

    int teamLeaderIndex;
    isCycled = true;
    while (isCycled) {
        cin >> teamLeaderIndex;
        if (teamLeaderIndex == 0) {
            return;
        }
        if ((teamLeaderIndex <= freeEmployees.size()) && (freeEmployees[teamLeaderIndex - 1].getProjectId() == project.getId())) {
            isCycled = false;
        } else if (teamLeaderIndex > freeEmployees.size()) {
            cout << "Неверный ввод\n";
        } else {
            cout << "Сотрудник не добавлен в проект\nПовторите попытку\n";
        }
    }

    freeEmployees[teamLeaderIndex - 1].setIsTeamLeader(true);

    FileService::clearFile("/Users/nasta/Desktop/employees.txt");

    for (auto &&employee:employees) {
        for (auto &&freeEmployee:freeEmployees) {
            if (freeEmployee.getId() == employee.getId()) {
                employee.setProjectId(freeEmployee.getProjectId());
                employee.setProjectName(freeEmployee.getProjectName());
                if (freeEmployee.isIsTeamLeader()) {
                    employee.setIsTeamLeader(true);
                }
                cout << freeEmployee;
            }
        }
        FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
    }

}

void AdminMenu::archieveProject() {
    vector<Project> projects;
    Project obj;
    int index = 1;
    int projectIndex;

    ifstream readFile("/Users/nasta/Desktop/projects.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (!obj.isIsArchieved()) {
            cout << index << ". " << obj;
            index++;
            projects.push_back(obj);
        }
    }
    readFile.close();
    cout << "\nВыберите проект: " << endl;
    cin >> projectIndex;
    if (projectIndex > projects.size()) {
        throw Exception("Неверный ввод\n");
    }

    projects[projectIndex - 1].setIsArchieved(true);
    int projectId = projects[projectIndex - 1].getId();
    vector<Employee> employees;

    Employee employeeObj;

    ifstream file("/Users/nasta/Desktop/employees.txt");
    while (file.read(reinterpret_cast<char *>(&employeeObj), sizeof(employeeObj))) {
        employees.push_back(employeeObj);
    }
    file.close();
    FileService::clearFile("/Users/nasta/Desktop/employees.txt");
    for (auto &&employee:employees) {
        if (employee.getProjectId() == projectId) {
            employee.setProjectId(0);
            employee.setProjectName("");
            if (employee.isIsTeamLeader()) {
                employee.setIsTeamLeader(false);
            }
        }
        FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
    }

    FileService::clearFile("/Users/nasta/Desktop/projects.txt");

    for (auto &&project:projects) {
        FileService::writeObject<Project>(project, "/Users/nasta/Desktop/projects.txt");
    }
}

bool sortByEmail (Employee i,Employee j) { return (i.getEmail() < j.getEmail()); }
bool sortByPosition (Employee i,Employee j) { return (i.getPosition() < j.getPosition()); }

void AdminMenu::addEmployee() {
    string newEmail;
    int positionIndex;
    string newPosition = "";
    string hash;
    bool isCycled = true;
    regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    Employee employeeObj;
    vector<Employee> employees;

    ifstream file("/Users/nasta/Desktop/employees.txt");

    while (file.read(reinterpret_cast<char *>(&employeeObj), sizeof(employeeObj))) {
        employees.push_back(employeeObj);
    }

    while (isCycled) {
        cout << "Введите email сотрудника: ";
        cin >> newEmail;
        cout << "Введите должность\n1. Разработчик\n2. Тестировщик" << endl;
        cin >> positionIndex;
        switch (positionIndex) {
            case 1:
                newPosition = "dev";
                break;
            case 2:
                newPosition = "tester";
                break;
            default:
                break;
        }
        int n = 0;
        for (auto &&employee:employees) {
            if (employee.getEmail() == newEmail) {
                break;
            }
            n++;
        }
        if ((regex_match(newEmail, emailRegex)) && (newPosition != "")) {
            if (n == employees.size()) {
                isCycled = false;
            } else {
                cout << "Email уже занят\n";
            }
        } else {
            cout << "Email и(или) должность введены неверно\nПовторите попытку\n";
        }
    }

    cout << "Назначить проект:\n";
    vector<Project> projects;
    Project obj;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/projects.txt");

    cout << "0. Не привязывать проект\n";
    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (!obj.isIsArchieved()) {
            cout << index << ". " << obj;
            index++;
            projects.push_back(obj);
        }
    }
    int projectIndex;
    cin >> projectIndex;


    if (projectIndex  > projects.size()) {
        throw Exception("Неверный ввод\n");
    }
    string projectName = "";
    int projectId = 0;
    if (projectIndex != 0) {
        projectId = projects[projectIndex - 1].getId();
        projectName = projects[projectIndex - 1].getName();
    }
    string tempPass = "";
    for (unsigned int i = 0; i < 6; i++) {
        tempPass += alphanum[rand() % stringLength];
    }
    cout << "Временный пароль нового сотрудника: " << tempPass << endl;
    hash = sha256(tempPass);
    Employee employee(newEmail, hash, newPosition, projectId, projectName, true);
    FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
}

void AdminMenu::showEmployees() {
    Employee obj;
    vector <Employee> employees;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        cout << index << ". " << obj;
        index++;
        employees.push_back(obj);
    }
    bool isCycled = true;
    while (isCycled) {
        index = 1;
        cout << "\nВыберите команду:\n";
        cout << "1. Сортировать по email\n2. Сортировать по должности\n0. Выйти в главное меню\n";
        int option;
        cin >> option;
        switch (option) {
            case 0:
                isCycled = false;
                break;
            case 1:
                sort(employees.begin(), employees.end(), sortByEmail);
                cout << "Результат:\n";
                for (auto &&employee:employees) {
                    cout << index++ << ". " << employee;
                }
                break;
            case 2:
                sort(employees.begin(), employees.end(), sortByPosition);
                cout << "Результат:\n";
                for (auto &&employee:employees) {
                    cout << index++ << ". " << employee;
                }
                break;
            default:
                cout << "Неверный ввод\n";
                break;
        }
    }
}

void AdminMenu::showProjects() {
    Project obj;
    vector <Project> projects;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/projects.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (!obj.isIsArchieved()) {
            cout << index << ". " << obj;
            index++;
            projects.push_back(obj);
        }
    }
}


void AdminMenu::showArchievedProjects() {
    Project obj;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/projects.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (obj.isIsArchieved()) {
            cout << index << ". " << obj;
            index++;
        }
    }
}

void AdminMenu::removeEmployee() {
    vector<Employee> employees;
    Employee obj;
    int index = 1;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    cout << "Выберите сотрудника\n(0 для отмены)" << endl;
    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        cout << index << ". " << obj;
        index++;
        employees.push_back(obj);
    }
    int employeeId;
    int employeeIndex = 1;
    cin >> employeeId;
    if (employeeId == 0) {
        return;
    } else if (employeeId  > employees.size()) {
        throw Exception("Неверный ввод\n");
    }
    FileService::clearFile("/Users/nasta/Desktop/employees.txt");

    for (auto &&employee:employees) {
        if (employeeIndex != employeeId) {
            FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
        }
        employeeIndex++;
    }
}


void AdminMenu::findEmployee() {
    vector<Employee> employees;
    Employee obj;

    ifstream readFile("/Users/nasta/Desktop/employees.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        employees.push_back(obj);
    }
    string searchField;
    cout << "Введите email сотрудника: ";
    cin >> searchField;

    for (auto &&employee:employees) {
        if (employee.getEmail().find(searchField) != string::npos) {
            return;
        }
    }
    cout << "Сотрудник не найден\n";
}

void AdminMenu::editTeam() {
    vector<Project> projects;
    Project obj;
    int index = 1;
    int projectIndex;

    ifstream readFile("/Users/nasta/Desktop/projects.txt");

    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if (!obj.isIsArchieved()) {
            cout << index << ". " << obj;
            index++;
            projects.push_back(obj);
        }
    }
    readFile.close();
    cout << "\nВыберите проект (0 для отмены): " << endl;
    cin >> projectIndex;
    if (projectIndex == 0) {
        return;
    } else if (projectIndex > projects.size()) {
        throw Exception("Неверный ввод\n");
    }
    int projectId = projects[projectIndex - 1].getId();
    string projectName = projects[projectIndex - 1].getName();

    vector<Employee> employees;
    vector<Employee> teamMembers;

    Employee employeeObj;

    ifstream file("/Users/nasta/Desktop/employees.txt");
    index = 1;
    while (file.read(reinterpret_cast<char *>(&employeeObj), sizeof(employeeObj))) {
        if (employeeObj.getProjectId() == projectId) {
            cout << index << ". " << employeeObj;
            index++;
            teamMembers.push_back(employeeObj);
        }
        employees.push_back(employeeObj);
    }
    file.close();
    int option;
    cout << "\nВыберите команду\n1. Добавить сотрудника\n2. Убрать сотрудника\n3. Сменить тимлида\n";
    cin >> option;
    switch(option) {
        case 1: {
            vector<Employee> notInProject;
            int teamMemberIndex;
            index = 1;

            for (auto &&employee:employees) {
                if (employee.getProjectId() == 0) {
                    notInProject.push_back(employee);
                    cout << index << ". " << employee;
                    index++;
                }
            }

            while (true) {
                cout << "Введите номера сотрудников для добавления в команду\n(Введите 0, чтобы закончить ввод): ";
                cin >> teamMemberIndex;
                if (teamMemberIndex == 0) {
                    break;
                } else if (teamMemberIndex > employees.size()) {
                    cout << "Неверный ввод\n";
                } else {
                    notInProject[teamMemberIndex - 1].setProjectId(projectId);
                    notInProject[teamMemberIndex - 1].setProjectName(projectName);
                }
            }

            FileService::clearFile("/Users/nasta/Desktop/employees.txt");

            for (auto &&employee:employees) {
                for (auto &&newEmployee:notInProject) {
                    if (employee.getId() == newEmployee.getId()) {
                        employee.setProjectId(newEmployee.getProjectId());
                        employee.setProjectName(newEmployee.getProjectName());
                    }
                }
                FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
            }
            cout << "Сотрудники добавлены\n";
            break;
        }
        case 2: {
            int teamMemberIndex;

            index = 1;

            for (auto &&employee:teamMembers) {
                cout << index << ". " << employee;
                index++;
            }

            if (teamMembers.size() == 1) {
                cout << "\nВы не можете удалить последнего сотрудника из проекта\nПожалуйста, добавьте другого сотрудника перед удалением\n";
                return;
            }

            cout << "Введите номер сотрудника для удаления из команды\n(Введите 0 для отмены): ";
            cin >> teamMemberIndex;
            if (teamMemberIndex == 0) {
                return;
            } else if (teamMemberIndex  > teamMembers.size()) {
                throw Exception("Неверный ввод\n");
            }
            if (teamMembers[teamMemberIndex - 1].isIsTeamLeader()) {
                cout << "Вы не можете удалить тимлида проекта\nСначала смените тимлида проекта\n";
                return;
            }

            FileService::clearFile("/Users/nasta/Desktop/employees.txt");

            for (auto &&employee:employees) {
                if (employee.getId() == teamMembers[teamMemberIndex - 1].getId()) {
                    employee.setProjectId(0);
                    employee.setProjectName("");
                }
                FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
            }
            cout << "Сотрудник удален из команды проекта\n";
            break;
        }
        case 3: {
            Employee obj;
            int teamMemberIndex;
            index = 1;

            for (auto &&employee:teamMembers) {
                cout << index << ". " << employee;
                index++;
            }

            cout << "Введите номер сотрудника\n(Введите 0 для отмены): ";
            cin >> teamMemberIndex;
            if (teamMemberIndex == 0) {
                return;
            } else if (teamMemberIndex  > teamMembers.size()) {
                throw Exception("Неверный ввод\n");
            }

            FileService::clearFile("/Users/nasta/Desktop/employees.txt");

            for (auto &&employee:employees) {
                if (employee.getId() == teamMembers[teamMemberIndex - 1].getId()) {
                    employee.setIsTeamLeader(true);
                }
                FileService::writeObject<Employee>(employee, "/Users/nasta/Desktop/employees.txt");
            }
            cout << "Сотрудник назначен тимлидом проекта\n";
            break;
        }
        default:
            cout << "Неверный ввод\n";
            break;
    }
}

#endif /* ADMINMENU_H_ */
