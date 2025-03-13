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

class Ship {
private:
    static int count;    
    int num;     
    Angle shir;     
    Angle dol;    
public:
    Ship() : num(++count) {}
    void get() {
        cout << "Введите координаты для корабля #" << num << ":\n";
        cout << "Широта:\n";
        shir.getAngle();
        cout << "Долгота:\n";
        dol.getAngle();
    }
    void show() const {
        cout << "Корабль #" << num << ":\n";
        cout << "Широта: ";
        shir.showAngle();
        cout << "Долгота: ";
        dol.showAngle();
    }
};
int Ship::count = 0;
int main() {
    setlocale(LC_ALL, "rus");
    const int x = 3;
    Ship ship[x];
    for (int i = 1; i <= x; i++) {
        ship[i].get();
    }
    for (int i = 1; i <= x; i++) {
        ship[i].show();
    }
    return 0;
}
