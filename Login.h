/*
 * Login.h
 *
 *  Created on: May 14, 2018
 *      Author: mark
 */


#ifndef LOGIN_H
#define LOGIN_H

class Login {
public:
    // Вход для администратора
    static bool loginAdmin();
    // Вход для сотрудника
    static bool loginEmployee();

    // Меню входа
    static void loginMenu();
};

bool Login::loginAdmin() {
    string email;
    string password;
    string hashedPassword;
    bool isFound = false;

    cout << "\nВведите email: ";
    cin >> email;
    cout << "Введите пароль: ";
    cin >> password;
    hashedPassword = sha256(password);

    Admin obj;
    ifstream readFile;
    readFile.open("/Users/nasta/Desktop/admins.txt", ios::in);
    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        string pass = string(obj.getPassword());
        if ((obj.getEmail() == email) && (pass == hashedPassword)) {
            isFound = true;
            break;
        }
    }
    if (isFound) {
        readFile.close();
        cout << "\nВы вошли в аккаунт.\n";
        return true;
    }
    cout << "\nТакого аккаунта нет.\n";
    readFile.close();
    return false;
}

bool Login::loginEmployee() {
    string email;
    string password;
    string hashedPassword;

    cout << "\nВведите email: ";
    cin >> email;
    cout << "Введите пароль: ";
    cin >> password;

    hashedPassword = sha256(password);

    Employee obj;
    ifstream readFile("/Users/nasta/Desktop/employees.txt");
    while (readFile.read(reinterpret_cast<char *>(&obj), sizeof(obj))) {
        if ((obj.getEmail() == email) && (obj.getPassword() == hashedPassword)) {
            cout << "\nВы вошли в аккаунт.\n";
            currentEmployee = new Employee(obj);
            readFile.close();
            return true;
        }
    }
    cout << "\nТакого аккаунта нет.\n";
    readFile.close();
    return false;
}

void Login::loginMenu() {
    int option;
    bool isCycled = true;
    do {
        cout << "\n1. Зайти как администратор.\n2. Зайти как сотрудник." << endl;
        cout << "Введите команду: ";
        cin >> option;

        switch (option) {
            case 1:
                if (loginAdmin()) {
                    try {
                        AdminMenu::showAdminMenu();
                    } catch (Exception &Obj) {
                        cout << Obj.what();
                    }
                };
                break;
            case 2: {
                if (loginEmployee()) {
                    if (currentEmployee->isIsTempPass()) {
                        EmployeeMenu::finishSignUp();
                    }
                    try {
                        EmployeeMenu::showMenu();
                    } catch (Exception&Obj) {
                        cout << Obj.what();
                    }
                };
                break;
            }
            default:
                cout << "\nТакого варианта нет." << endl;
                break;
        }

    } while (isCycled);
}

#endif //LOGIN_H
