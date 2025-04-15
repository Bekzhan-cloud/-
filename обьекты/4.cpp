// вызвано всего 3 функции

#include <iostream>
using namespace std;

class Employee {
private:
    int num;       // Номер сотрудника
    float salary;  // Оклад сотрудника

public:
    // Конструктор по умолчанию
    Employee() : num(0), salary(0.0) {}

    // Функция ввода данных
    void getData() {
        cout << "Введите номер сотрудника: ";
        cin >> num;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }

    // Функция отображения данных
    void displayData() const {
        cout << "Номер сотрудника: " << num << endl;
        cout << "Оклад сотрудника: $" << salary << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Employee emp1, emp2, emp3;

    // Ввод данных для каждого сотрудника
    cout << "Введите данные для первого сотрудника:\n";
    emp1.getData();
    cout << "Введите данные для второго сотрудника:\n";
    emp2.getData();
    cout << "Введите данные для третьего сотрудника:\n";
    emp3.getData();

    // Вывод данных сотрудников
    cout << "\n----- Данные сотрудников -----\n";
    cout << "\nДанные первого сотрудника:\n";
    emp1.displayData();
    cout << "\nДанные второго сотрудника:\n";
    emp2.displayData();
    cout << "\nДанные третьего сотрудника:\n";
    emp3.displayData();

    return 0;
}
