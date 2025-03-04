#include <iostream>
using namespace std;

struct beka_date {
    int day;
    int month;
    int year;
};

int main() {
    beka_date today;

    cout << "Введите дату (день/месяц/год): ";
    cin >> today.day >> today.month >> today.year;

    cout << "Вы ввели дату: " << today.day << "/" << today.month << "/" << today.year << endl;
    
    return 0;
}
