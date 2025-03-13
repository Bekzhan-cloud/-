#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class employee {
private:
    string name;
    long number;
public:
    void getdata() {
        cout << "Введите имя сотрудника: ";
        cin >> name;
        cout << "Введите номер сотрудника: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Имя: " << name << ", Номер: " << number << endl;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int max = 100;
    employee employees[max];
    int n;
    link:
    cout << "Сколько сотрудников вы хотите ввести (макс 100)? ";
    cin >> n;
    if (n > max) {
        cout << "Можно ввести не более 100 сотрудников." << endl;
        goto link;
    }
    for (int i = 0; i < n; ++i) {
        cout << "Введите данные для сотрудника #" << (i + 1) << ":" << endl;
        employees[i].getdata();
    }
    cout << "\nДанные всех сотрудников:\n";
    for (int i = 0; i < n; ++i) {
        employees[i].putdata();
    }
    return 0;
}

