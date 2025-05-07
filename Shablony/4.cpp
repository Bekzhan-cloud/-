#include <iostream>
using namespace std;

template <typename T>
class frac {
private:
    T numerator;  // числитель
    T denominator;  // знаменатель

public:
    // Конструктор
    frac(T num = 0, T denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
    }

    // Получение числителя
    T getNumerator() const {
        return numerator;
    }

    // Получение знаменателя
    T getDenominator() const {
        return denominator;
    }

    // Операция сложения
    frac operator+(const frac& other) const {
        T num = numerator * other.denominator + other.numerator * denominator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // Операция вычитания
    frac operator-(const frac& other) const {
        T num = numerator * other.denominator - other.numerator * denominator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // Операция умножения
    frac operator*(const frac& other) const {
        T num = numerator * other.numerator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // Операция деления
    frac operator/(const frac& other) const {
        T num = numerator * other.denominator;
        T denom = denominator * other.numerator;
        if (denom == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return frac(num, denom);
    }

    
    void print() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    int choice;
    cout << "Калькулятор с дробями. Выберите тип данных:\n1. char\n2. int\n0. Выход\nВаш выбор: ";
    cin >> choice;

    if (choice == 0) {
        cout << "Выход из программы...\n";
        return 0;
    }

    if (choice == 1 || choice == 2) {
        cout << "Введите числитель и знаменатель для первой дроби: ";
        int num1, denom1;
        cin >> num1 >> denom1;

        cout << "Введите числитель и знаменатель для второй дроби: ";
        int num2, denom2;
        cin >> num2 >> denom2;

        if (choice == 1) {
            frac<char> f1(static_cast<char>(num1), static_cast<char>(denom1));
            frac<char> f2(static_cast<char>(num2), static_cast<char>(denom2));

            cout << "Сложение: ";
            frac<char> sum = f1 + f2;
            sum.print();
            cout << endl;

            cout << "Вычитание: ";
            frac<char> diff = f1 - f2;
            diff.print();
            cout << endl;

            cout << "Умножение: ";
            frac<char> prod = f1 * f2;
            prod.print();
            cout << endl;

            cout << "Деление: ";
            frac<char> div = f1 / f2;
            div.print();
            cout << endl;
        }
        else {
            frac<int> f1(num1, denom1);
            frac<int> f2(num2, denom2);

            cout << "Сложение: ";
            frac<int> sum = f1 + f2;
            sum.print();
            cout << endl;

            cout << "Вычитание: ";
            frac<int> diff = f1 - f2;
            diff.print();
            cout << endl;

            cout << "Умножение: ";
            frac<int> prod = f1 * f2;
            prod.print();
            cout << endl;

            cout << "Деление: ";
            frac<int> div = f1 / f2;
            div.print();
            cout << endl;
        }
    }
    else {
        cout << "Неверный выбор.\n";
    }

    return 0;
}
