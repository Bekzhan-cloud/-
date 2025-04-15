#include <iostream>
using namespace std;
class Angle {
private:
    int degrees;
    float minutes;
    char direction;
public:
    Angle() : degrees(0), minutes(0.0), direction('N') {}
    Angle(int d, float m, char dir) : degrees(d), minutes(m), direction(dir) {}
    void getAngle() {
        cout << "Введите градусы: ";
        cin >> degrees;
        cout << "Введите минуты: ";
        cin >> minutes;
        cout << "Введите направление (N, S, E, W): ";
        cin >> direction;
    }
    void showAngle() const {
        cout << degrees << '\xB0' << minutes << "' " << direction << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Angle angle1(149, 34.8, 'W');
    cout << "Изначальная координата: ";
    angle1.showAngle();
    Angle angle2;
    char choice;
    do {
        angle2.getAngle();
        cout << "Введенная координата: ";
        angle2.showAngle();
        cout << "Хотите ввести еще одну координату? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
