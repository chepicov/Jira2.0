//============================================================================
// Name        : 0.cpp
// Author      : Mark
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdio>
#include<iomanip>
#include<fstream>
#include<list>
#include<algorithm>
#include<iterator>
#include<locale>
#include <ctime>
#include "string.h"

using namespace std;

#include "SHA256.h"
#include "User.h"
#include "Admin.h"
#include "Employee.h"
#include "Project.h"
#include "Team.h"
#include "Task.h"

int main() {
    srand(time(0));
    cout << "Выберите режим входа:" << endl;
    cout << "1. Администратор" << endl;
    cout << "2. Сотрудник" << endl;
    int mode;
    cin >> mode;
    switch (mode) {
    case 1: {
        Admin *admin = new Admin();
    	admin->login(mode);
    	break;
    }
    default:
    	Employee *employee = new Employee();
    	employee->login(mode);
    	break;
    }
	return 0;
}
