#include <iostream>
using namespace std;
loat circarea(float radius);
int main() {
    float radius;
    cout << "Введите радиус круга: ";
    cin >> radius;
    cout << "Площадь круга: " << circarea(radius) << endl;
    return 0;
}
float circarea(float radius) {
    return 3.14159f * radius * radius;
}
