#include <iostream>
#include <cstring>
#include <cstdlib>  // для atof()
#include <cctype>   // для isdigit()
#include <stdexcept>
using namespace std;

class String {
private:
    enum { SZ = 80 };
    char str[SZ];

    // Проверка на наличие чисел < 65
    bool containsBadScore(const char* buf) {
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (isdigit(buf[i])) {
                char numBuf[16] = { 0 };
                int j = 0;

                while ((isdigit(buf[i]) || buf[i] == '.') && j < 15) {
                    numBuf[j++] = buf[i++];
                }
                numBuf[j] = '\0';

                double val = atof(numBuf);
                if (val < 65.0) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    class TooLongInit : public runtime_error {
    public:
        TooLongInit() : runtime_error("Ошибка: строка инициализации слишком длинная.") {}
    };

    class ConcatenationOverflow : public runtime_error {
    public:
        ConcatenationOverflow() : runtime_error("Ошибка: переполнение при конкатенации строк.") {}
    };

    class BadIntentException : public runtime_error {
    public:
        BadIntentException() : runtime_error("Ошибка: Обнаружен педагогический саботаж! (введена фраза вроде «не поставлю» или число ниже 65 — а мы ведь за взаимную доброту!').") {}
    };

    String() {
        strcpy(str, "");
    }

    String(const char s[]) {
        if (strlen(s) >= SZ)
            throw TooLongInit();
        strcpy(str, s);
    }

    void display() const {
        cout << str;
    }

    void input(const char* prompt, const char* defaultStr) {
        cout << prompt << " (по умолчанию: \"" << defaultStr << "\"):\n> ";
        char buf[SZ * 2];
        cin.getline(buf, SZ * 2);

        if (strlen(buf) == 0) {
            strcpy(str, defaultStr);
        }
        else {
            if (strlen(buf) >= SZ)
                throw TooLongInit();

            // Проверка на запрещённые фразы и числа < 65
            if (strstr(buf, "не поставлю") || strstr(buf, "меньше 65") || containsBadScore(buf))
                throw BadIntentException();

            strcpy(str, buf);
        }
    }

    String operator+(const String& ss) const {
        if (strlen(str) + strlen(ss.str) >= SZ)
            throw ConcatenationOverflow();

        String temp;
        strcpy(temp.str, str);
        strcat(temp.str, ss.str);
        return temp;
    }
};

int main() {
    try {
        String s1, s2, s3;
        s1.input("Введите первую строку", "Поставлю ");
        s2.input("Введите вторую строку", "80 баллов!");

        cout << "\nСложение строк...\n";
        s3 = s1 + s2;

        cout << "\nРезультат:\n";
        s3.display();
        cout << endl;
    }
    catch (const String::TooLongInit& e) {
        cerr << e.what() << "\nЗавершение программы." << endl;
    }
    catch (const String::ConcatenationOverflow& e) {
        cerr << e.what() << "\nЗавершение программы." << endl;
    }
    catch (const String::BadIntentException& e) {
        cerr << e.what() << "\nПопробуйте снова с позитивной формулировкой.\n";
    }
    catch (...) {
        cerr << "Неизвестная ошибка.\n";
    }

    return 0;
}
