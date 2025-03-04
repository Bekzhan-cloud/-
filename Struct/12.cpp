#include <iostream>
using namespace std;

struct beka_fraction {
    int numerator;
    int denominator;
};

beka_fraction addFractions(beka_fraction f1, beka_fraction f2) {
    beka_fraction sum;
    sum.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    sum.denominator = f1.denominator * f2.denominator;
    return sum;
}

int main() {
    beka_fraction f1, f2, result;
    char op;

    cout << "Введите первую дробь (числитель/знаменатель): ";
    cin >> f1.numerator >> f1.denominator;
    cout << "Введите оператор (+): ";
    cin >> op;
    cout << "Введите вторую дробь (числитель/знаменатель): ";
    cin >> f2.numerator >> f2.denominator;

    if (op == '+') {
        result = addFractions(f1, f2);
    }

    cout << "Результат: " << result.numerator << "/" << result.denominator << endl;

    return 0;
}
