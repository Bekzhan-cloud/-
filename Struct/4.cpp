#include <iostream>
using namespace std;

struct beka_employee {
    int id;
    float salary;
};

int main() {
    beka_employee emp1, emp2, emp3;

    cout << "Введите данные о сотруднике (номер и зарплату): ";
    cin >> emp1.id >> emp1.salary;

    cout << "Сотрудник: " << emp1.id << ", зарплата: $" << emp1.salary << endl;
    
    return 0;
}
