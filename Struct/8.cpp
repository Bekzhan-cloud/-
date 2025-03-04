#include <iostream>
using namespace std;

struct beka_fraction {
    int numerator;
    int denominator;
};

int main() {
    beka_fraction f1, f2, sum;

    cout << "Введите первую дробь (числитель и знаменатель): ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Введите вторую дробь (числитель и знаменатель): ";
    cin >> f2.numerator >> f2.denominator;

    sum.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    sum.denominator = f1.denominator * f2.denominator;

    cout << "Сумма дробей: " << sum.numerator << "/" << sum.denominator << endl;

    return 0;
}
