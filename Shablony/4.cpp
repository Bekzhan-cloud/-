#include <iostream>
using namespace std;

template <typename T>
class frac {
private:
    T numerator;  // ���������
    T denominator;  // �����������

public:
    // �����������
    frac(T num = 0, T denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "������: ������� �� ����!" << endl;
            exit(1);
        }
    }

    // ��������� ���������
    T getNumerator() const {
        return numerator;
    }

    // ��������� �����������
    T getDenominator() const {
        return denominator;
    }

    // �������� ��������
    frac operator+(const frac& other) const {
        T num = numerator * other.denominator + other.numerator * denominator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // �������� ���������
    frac operator-(const frac& other) const {
        T num = numerator * other.denominator - other.numerator * denominator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // �������� ���������
    frac operator*(const frac& other) const {
        T num = numerator * other.numerator;
        T denom = denominator * other.denominator;
        return frac(num, denom);
    }

    // �������� �������
    frac operator/(const frac& other) const {
        T num = numerator * other.denominator;
        T denom = denominator * other.numerator;
        if (denom == 0) {
            cout << "������: ������� �� ����!" << endl;
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
    cout << "����������� � �������. �������� ��� ������:\n1. char\n2. int\n0. �����\n��� �����: ";
    cin >> choice;

    if (choice == 0) {
        cout << "����� �� ���������...\n";
        return 0;
    }

    if (choice == 1 || choice == 2) {
        cout << "������� ��������� � ����������� ��� ������ �����: ";
        int num1, denom1;
        cin >> num1 >> denom1;

        cout << "������� ��������� � ����������� ��� ������ �����: ";
        int num2, denom2;
        cin >> num2 >> denom2;

        if (choice == 1) {
            frac<char> f1(static_cast<char>(num1), static_cast<char>(denom1));
            frac<char> f2(static_cast<char>(num2), static_cast<char>(denom2));

            cout << "��������: ";
            frac<char> sum = f1 + f2;
            sum.print();
            cout << endl;

            cout << "���������: ";
            frac<char> diff = f1 - f2;
            diff.print();
            cout << endl;

            cout << "���������: ";
            frac<char> prod = f1 * f2;
            prod.print();
            cout << endl;

            cout << "�������: ";
            frac<char> div = f1 / f2;
            div.print();
            cout << endl;
        }
        else {
            frac<int> f1(num1, denom1);
            frac<int> f2(num2, denom2);

            cout << "��������: ";
            frac<int> sum = f1 + f2;
            sum.print();
            cout << endl;

            cout << "���������: ";
            frac<int> diff = f1 - f2;
            diff.print();
            cout << endl;

            cout << "���������: ";
            frac<int> prod = f1 * f2;
            prod.print();
            cout << endl;

            cout << "�������: ";
            frac<int> div = f1 / f2;
            div.print();
            cout << endl;
        }
    }
    else {
        cout << "�������� �����.\n";
    }

    return 0;
}
