#include <iostream>
using namespace std;
double power(double n, int p = 2);
int main() {
    double num;
    int exp;
    cout << "Введите число и степень (по умолчанию 2): ";
    cin >> num >> exp;
    cout << "Результат: " << power(num, exp) << endl;
    return 0;
}
double power(double n, int p = 2) {
    double result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}
