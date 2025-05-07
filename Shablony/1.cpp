#include <iostream>
using namespace std;


template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Меню swaps() ===\n";
        cout << "1 - Обменять два int\n";
        cout << "2 - Обменять два float\n";
        cout << "3 - Обменять два char\n";
        cout << "0 - Выход\n";
        cout << "Выберите вариант: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Неверный ввод. Попробуйте снова.\n";
            continue;
        }

        if (choice == 1) {
            int a, b;
            cout << "Введите два целых числа: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "После swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 2) {
            float a, b;
            cout << "Введите два числа с плавающей точкой: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "После swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 3) {
            char a, b;
            cout << "Введите два символа: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "После swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 0) {
            cout << "Выход из программы.\n";
            break;
        }
        else {
            cout << "Неверный выбор.\n";
        }
    }

    return 0;
}
