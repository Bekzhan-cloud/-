#include <iostream>
using namespace std;
void zeroSmaller(int &a, int &b);

int main() {
    int x, y;
    cout << "Введите два числа: ";
    cin >> x >> y;
    zeroSmaller(x, y);
    cout << "Результат: " << x << " " << y << endl;
    return 0;
}
void zeroSmaller(int &a, int &b) {
    if (a < b) a = 0;
    else b = 0;
}
