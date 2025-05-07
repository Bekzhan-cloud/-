#include <iostream>
using namespace std;


template <typename T>
T amax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Меню amax() ===\n";
        cout << "1 - Найти максимум в int-массиве\n";
        cout << "2 - Найти максимум в float-массиве\n";
        cout << "3 - Найти максимум в char-массиве\n";
        cout << "0 - Выход\n";
        cout << "Выберите вариант: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка ввода. Попробуйте снова.\n";
            continue;
        }

        if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }

        int size;
        cout << "Введите размер массива: ";
        cin >> size;

        if (size <= 0 || cin.fail()) {
            cout << "Неверный размер массива. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            int* arr = new int[size];
            cout << "Введите " << size << " целых чисел:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "Максимум: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else if (choice == 2) {
            float* arr = new float[size];
            cout << "Введите " << size << " чисел с плавающей точкой:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "Максимум: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else if (choice == 3) {
            char* arr = new char[size];
            cout << "Введите " << size << " символов:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "Максимум: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
