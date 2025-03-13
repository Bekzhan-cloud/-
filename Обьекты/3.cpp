// вызвано всего 3 функции

#include <iostream>
using namespace std;

class timee {
private:
    int hour;
    int min;
    int sec;

public:
    // Конструктор по умолчанию
    timee() : hour(0), min(0), sec(0) {}

    // Конструктор с параметрами
    timee(int h, int m, int s) : hour(h), min(m), sec(s) {}

    // Функция вывода времени
    void print() {
        cout << (hour < 10 ? "0" : "") << hour << ":"
             << (min < 10 ? "0" : "") << min << ":"
             << (sec < 10 ? "
