#include <iostream>
#include <cmath>
using namespace std;
class Fraction {
private:
    int chis; 
    int znam; 
    void lowterms() {
        long tnum, tden, temp, gcd;
        tnum = labs(chis);  
        tden = labs(znam);
        if (tden == 0) {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0) {
            chis = 0;
            znam = 1;
            return;
        }
        while (tnum != 0) {
            if (tnum < tden) { 
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden; 
        }
        gcd = tden; 
        chis = chis / gcd;
        znam = znam / gcd;
    }

public:
    Fraction() : chis(0), znam(1) {}
    Fraction(int n, int d) : chis(n), znam(d) {
        lowterms();
    }
    void getFraction() {
        char slash;
        cout << "Введите дробь в формате числитель/знаменатель: ";
        cin >> chis >> slash >> znam;
        lowterms(); 
    }
    void showFraction() const {
        cout << chis << "/" << znam << endl;
    }
    Fraction add(const Fraction& f) const {
        int num = chis * f.znam + f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction subtract(const Fraction& f) const {
        int num = chis * f.znam - f.chis * znam;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction multiply(const Fraction& f) const {
        int num = chis * f.chis;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
    Fraction divide(const Fraction& f) const {
        int num = chis * f.znam;
        int den = znam * f.chis;
        return Fraction(num, den);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    char choice;
    do {
       
        Fraction frac1, frac2;
        cout << "Введите первую дробь:\n";
        frac1.getFraction();
        cout << "Введите вторую дробь:\n";
        frac2.getFraction();

        cout << "Выберите операцию (+, -, *, /): ";
        char operation;
        cin >> operation;

        Fraction result;
        switch (operation) {
        case '+':
            result = frac1.add(frac2);
            break;
        case '-':
            result = frac1.subtract(frac2);
            break;
        case '*':
            result = frac1.multiply(frac2);
            break;
        case '/':
            result = frac1.divide(frac2);
            break;
        default:
            cout << "Неправильный ввод операции!\n";
            continue;
        }

        cout << "Результат операции: ";
        result.showFraction();

        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
