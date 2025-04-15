// 3.cpp :
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

void bsort(const char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                const char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void order(const char* arr[], int n) {
    bsort(arr, n);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);     

    const int DAYS = 7;
    const char* days[DAYS] = {
        "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"
    };

    cout << "До сортировки:\n";
    for (int i = 0; i < DAYS; i++) {
        cout << days[i] << endl;
    }

    order(days, DAYS);

    cout << "\nПосле сортировки:\n";
    for (int i = 0; i < DAYS; i++) {
        cout << days[i] << endl;
    }

    return 0;
}
