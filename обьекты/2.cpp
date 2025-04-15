// вызвано всего 3 функции

#include <iostream>
using namespace std;

class TollBooth {
private:
    unsigned int count;  // Количество автомобилей
    double sum;          // Суммарная выручка

public:
    TollBooth() : count(0), sum(0.0) {}  // Конструктор

    void plat() {  // Платный проезд
        count++;
        sum += 0.50;
    }

    void neplat() {  // Бесплатный проезд
        count++;
    }

    void print() const {  // Вывод результата
        cout << "Количество машин: " << count << endl;
        cout << "Суммарная выручка: " << sum << " сом" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    TollBooth number;

    char x;
    cout << "Нажмите 'o', если автомобиль заплатил за проезд." << endl
         << "Нажмите 'x', если автомобиль не заплатил за проезд." << endl
         << "Нажмите 'e', если хотите выйти." << endl;

    while (true) {
        cin >> x;
        switch (x) {
            case 'o': 
                number.plat();
                break;
            case 'x': 
                number.neplat();
                break;
            case 'e': 
                number.print();
                return 0;
            default: 
                cout << "Вы ввели неверный символ!" << endl;
                break;
        }
    }
}
