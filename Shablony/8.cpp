#include <iostream>
#include <cstring>
#include <cstdlib>  // ��� atof()
#include <cctype>   // ��� isdigit()
#include <stdexcept>
using namespace std;

class String {
private:
    enum { SZ = 80 };
    char str[SZ];

    // �������� �� ������� ����� < 65
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
        TooLongInit() : runtime_error("������: ������ ������������� ������� �������.") {}
    };

    class ConcatenationOverflow : public runtime_error {
    public:
        ConcatenationOverflow() : runtime_error("������: ������������ ��� ������������ �����.") {}
    };

    class BadIntentException : public runtime_error {
    public:
        BadIntentException() : runtime_error("������: ��������� �������������� �������! (������� ����� ����� ��� ��������� ��� ����� ���� 65 � � �� ���� �� �������� �������!').") {}
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
        cout << prompt << " (�� ���������: \"" << defaultStr << "\"):\n> ";
        char buf[SZ * 2];
        cin.getline(buf, SZ * 2);

        if (strlen(buf) == 0) {
            strcpy(str, defaultStr);
        }
        else {
            if (strlen(buf) >= SZ)
                throw TooLongInit();

            // �������� �� ����������� ����� � ����� < 65
            if (strstr(buf, "�� ��������") || strstr(buf, "������ 65") || containsBadScore(buf))
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
        s1.input("������� ������ ������", "�������� ");
        s2.input("������� ������ ������", "80 ������!");

        cout << "\n�������� �����...\n";
        s3 = s1 + s2;

        cout << "\n���������:\n";
        s3.display();
        cout << endl;
    }
    catch (const String::TooLongInit& e) {
        cerr << e.what() << "\n���������� ���������." << endl;
    }
    catch (const String::ConcatenationOverflow& e) {
        cerr << e.what() << "\n���������� ���������." << endl;
    }
    catch (const String::BadIntentException& e) {
        cerr << e.what() << "\n���������� ����� � ���������� �������������.\n";
    }
    catch (...) {
        cerr << "����������� ������.\n";
    }

    return 0;
}
