// 1.cpp :
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    float* a = new float[n];
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i);
    }

    float s = 0;
    float* p = a;

    for (int i = 0; i < n; i++) {
        s += *(p + i);
    }
    cout << "Среднее арифметическое: " << s / n << endl;

    delete[] a;
    return 0;
}
