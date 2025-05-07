#include <iostream>
#include <string>
#include <cstdlib>   
#include <stdexcept> 
#include <limits>
using namespace std;

// ---------------- Исключения ---------------- //
class FeetException : public runtime_error {
public:
    FeetException(const string& msg) : runtime_error(msg) {}
};

class InchesException : public runtime_error {
public:
    InchesException(const string& msg) : runtime_error(msg) {}
};


int isFeet(const string& str) {
    int slen = str.size();
    if (slen == 0 || slen > 5)
        throw FeetException("Ошибка: ничего не введено или слишком много символов.");

    for (int j = 0; j < slen; j++) {
        if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
            throw FeetException("Ошибка: недопустимый символ в числе футов.");
    }

    double n = atof(str.c_str());
    if (n < -999.0 || n > 999.0)
        throw FeetException("Ошибка: число футов выходит за пределы допустимых значений (-999 до 999).");

    return 1;
}


class Distance {
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0f) {}

    Distance(int ft, float in) {
        if (in < 0.0f || in >= 12.0f)
            throw InchesException("Ошибка в конструкторе: дюймы должны быть от 0.0 до 11.99.");
        if (ft < -999 || ft > 999)
            throw FeetException("Ошибка в конструкторе: футы должны быть от -999 до 999.");

        feet = ft;
        inches = in;
    }

    void showdist() const {
        cout << feet << "\'-" << inches << '\"';
    }

    void getdist() {
        string instr;
        while (true) {
            try {
                cout << "\nВведите футы: ";
                cin >> instr;
                if (isFeet(instr)) {
                    feet = atoi(instr.c_str());
                    break;
                }
            }
            catch (const FeetException& e) {
                cout << e.what() << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        while (true) {
            try {
                cout << "Введите дюймы: ";
                cin >> inches;

                if (cin.fail())
                    throw InchesException("Ошибка: введены нечисловые символы вместо дюймов.");

                if (inches < 0.0 || inches >= 12.0)
                    throw InchesException("Ошибка: дюймы должны быть от 0.0 до 11.99.");

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            catch (const InchesException& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
};


int main() {
    char ans;
    do {
        try {
            Distance d;
            d.getdist();
            cout << "\nРасстояние = ";
            d.showdist();
        }
        catch (const exception& e) {
            cout << "\nПроизошло исключение: " << e.what() << endl;
        }

        cout << "\nЕще раз (y/n)? ";
        cin >> ans;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (ans != 'n');

    return 0;
}
