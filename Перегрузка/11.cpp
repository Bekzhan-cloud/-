#include <iostream>
#include <cmath> 
using namespace std;

class Sterling {
private:
    long pounds;    
    int shillings;  
    int pence;      
public:
    // Конструктор без аргументов
    Sterling() : pounds(0), shillings(0), pence(0) {}
    // Конструктор с одним аргументом (десятичные фунты)
    Sterling(double decimalPounds) {
        pounds = static_cast<long>(decimalPounds);
        double fractionalPart = (decimalPounds - pounds) * 20;
        shillings = static_cast<int>(fractionalPart);
        pence = static_cast<int>(round((fractionalPart - shillings) * 12)); 
    }
    // Конструктор с тремя аргументами
    Sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}

    void getdata() {
        char ch;
        cout << "Введите футы: "; cin >> pounds;
        cout << "Введите шиллинги: "; cin >> shillings;
        cout << "Введите пенсы: "; cin >> pence;
    }
    void putdata() const {
        cout << pounds << "." << shillings << "." << pence << endl;
    }
    Sterling operator+(const Sterling& s) const {
        return Sterling(double(*this) + double(s));
    }
    Sterling operator-(const Sterling& s) const {
        return Sterling(double(*this) - double(s));
    }
    Sterling operator*(double factor) const {
        return Sterling(double(*this) * factor);
    }
    double operator/(const Sterling& s) const {
        return double(*this) / double(s);
    }
    Sterling operator/(double divisor) const {
        if (divisor == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        return Sterling(double(*this) / divisor);
    }
    explicit operator double() const {
        return pounds + (shillings / 20.0) + (pence / 240.0);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Sterling s1, s2, result;
    double factor;
    cout << "Введите первое значение: ";
    s1.getdata();
    cout << "Введите второе значение: ";
    s2.getdata();
    result = s1 + s2;
    cout << "Сложение: ";
    result.putdata();
    result = s1 - s2;
    cout << "Вычитание: ";
    result.putdata();
    cout << "Введите множитель: ";
    cin >> factor;
    result = s1 * factor;
    cout << "Умножение: ";
    result.putdata();
    cout << "Деление (Sterling / Sterling): " << (s1 / s2) << endl;
    cout << "Введите делитель: ";
    cin >> factor;
    result = s1 / factor;
    cout << "Деление: ";
    result.putdata();

    return 0;
}

