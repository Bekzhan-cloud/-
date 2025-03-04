#include <iostream>
using namespace std;

enum beka_etype { laborer, secretary, manager, accountant, executive, researcher };

struct beka_date {
    int day, month, year;
};

struct beka_employee {
    int id;
    float salary;
    beka_etype position;
    beka_date hire_date;
};

int main() {
    beka_employee employees[3];

    for (int i = 0; i < 3; i++) {
        char ch;
        cout << "Введите ID сотрудника, зарплату, должность (l, s, m, a, e, r) и дату принятия (дд мм гггг): ";
        cin >> employees[i].id >> employees[i].salary >> ch;
        cin >> employees[i].hire_date.day >> employees[i].hire_date.month >> employees[i].hire_date.year;

        switch (ch) {
            case 'l': employees[i].position = laborer; break;
            case 's': employees[i].position = secretary; break;
            case 'm': employees[i].position = manager; break;
            case 'a': employees[i].position = accountant; break;
            case 'e': employees[i].position = executive; break;
            case 'r': employees[i].position = researcher; break;
            default: cout << "Некорректный ввод"; return 1;
        }
    }

    cout << "Список сотрудников:\n";
    for (int i = 0; i < 3; i++) {
        cout << "ID: " << employees[i].id << ", Зарплата: $" << employees[i].salary
             << ", Дата приема: " << employees[i].hire_date.day << "/"
             << employees[i].hire_date.month << "/" << employees[i].hire_date.year << endl;
    }

    return 0;
}
