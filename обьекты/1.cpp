#include <iostream>
using namespace std;

class Int {
private:
    int val;

public:
    // Конструкторы
    Int() : val(0) {}
    Int(int x) : val(x) {}

    // Методы установки значения
    void setZero() { val = 0; }
    void setValue(int x) { val = x; }

    // Метод вывода
    void print() const {
        cout << val << endl;
    }

    // Перегрузка оператора +
    Int operator+(const Int& n) const {
        return Int(val + n.val);
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    Int num1(100), num2(150), num3;
    num3 = num1 + num2;

    cout << "Первое слагаемое = ";
    num1.print();

    cout << "Второе слагаемое = ";
    num2.print();

    cout << "Результат = ";
    num3.print();

    return 0;
}

