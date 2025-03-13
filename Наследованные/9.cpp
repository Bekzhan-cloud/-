#include <iostream> 
#include <string> 
#include <Windows.h>
using namespace std;
class publication {
private:
    string name;
    float price;
public:
    void getdata() {
        cout << "\nВведите заголовок: "; cin >> name;
        cout << "Введите цену: "; cin >> price;
    }
    void putdata()const {
        cout << "Заголовок: " << name;
        cout << "\nЦена: " << price;
    }
};
class date :public publication {
private:
    int day;
    int month;
    int year;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите дату выхода книги:\n";
        cout << "Введите день: "; cin >> day;
        cout << "Введите месяц: "; cin >> month;
        cout << "Введите год: "; cin >> year;
    }
    void putdata() const {
        publication::putdata();
        cout<<"\nДата выхода книги: " << (day < 10 ? "0" : "") << day << "."
            << (month < 10 ? "0" : "") << month << "."
            << (year < 1000 ? "0" : "") << year << endl;
    }
};
class book :private date {
private:
    int str;
public:
    void getdata() {
        date::getdata();
        cout << "Введите число страниц: "; cin >> str;
    }
    void putdata()const {
        date::putdata();
        cout << "Страниц: " << str;
    }
};
class tape :private book {
private:
    float min;
public:
    void getdata() {
        book::getdata();
        cout << "Введите время звучания: "; cin >> min;
    }
    void putdata()const {
        book::putdata();
        cout << "\nВремя звучания: " << min << " минут";
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    tape t1, t2;
    cout << "Введите данные для первой книги:";
    t1.getdata();
    cout << "\nВведите данные для второй книги: ";
    t2.getdata();
    cout << endl;
    cout << "Данные первой книги:\n";
    t1.putdata();
    cout << "\n\nДанные второй книги:\n";
    t2.putdata();
    return 0;
}
