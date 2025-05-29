#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    vector<float> numbers;
    char choice;

    do {
        cout << "Введите число с плавающей запятой: ";
        float input;
        cin >> input;
        numbers.push_back(input);

        cout << "Продолжать ('y' или 'n'): ";
        cin >> choice;
    } while (choice == 'y');

    sort(numbers.begin(), numbers.end());

    cout << "Отсортированные числа: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1)
            cout << ", ";
    }
    cout << endl;

    return 0;
}
