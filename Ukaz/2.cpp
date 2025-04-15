#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
private:
    char* str;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy_s(str, strlen(s) + 1, s);
    }

    ~String() {
        delete[] str;
    }

    void display() const {
        cout << str << endl;
    }

    void upit() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);
        }
    }
};

int main() {
    String s1("bekzhan");
    s1.display();
    s1.upit();
    s1.display();

    return 0;
}
