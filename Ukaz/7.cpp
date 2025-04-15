// 7.cpp :
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class p {
    char n[40];
    float s;
public:
    void set() {
        cout << "Имя: "; cin >> n;
        cout << "Зарплата: "; cin >> s;
    }
    void print() const {
        cout << n << " — " << s << endl;
    }
    float get() const {
        return s;
    }
};

void sort(p** pp, int size) {
    for (int j = 0; j < size - 1; j++)
        for (int k = j + 1; k < size; k++)
            if ((*(pp + j))->get() > (*(pp + k))->get()) {
                p* tmp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = tmp;
            }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int n = 3;
    p* arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = new p;
        arr[i]->set();
    }

    sort(arr, n);

    cout << "\nОтсортированные:\n";
    for (int i = 0; i < n; i++) {
        arr[i]->print();
        delete arr[i];
    }

    return 0;
}
