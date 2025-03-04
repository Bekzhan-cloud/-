#include <iostream>
#include <string>
using namespace std;
class publication{
protected:
    string title;
    float price;
public:
    void getdata() {
            cout << "Введите название: ";
            cin.ignore();
            getline(cin, title);
            cout << "Введите цену: ";
            cin >> price;
        }
        void putdata() const {
            cout << "Название: " << title << endl;
            cout << "Цена: " << price << " USD" << endl;
        }
};
class Book:publication{
private:
    int kol_str;
public:
    void getdata() {
        publication::getdata();
        cout << "Введите кол стр: ";
        cin >> kol_str;
    }
    void putdata() const {
        publication::putdata();
        cout << "Страниц: " << kol_str << endl;
    }
};
class Tape : public publication {
private:
    float play_time;
public:
    void getdata() {
        publication::getdata();
        cout << "Время записи(минуты): ";
        cin >> play_time;
    }
    void putdata() const {
        publication::putdata();
        cout << "Время записи: " << play_time << " минуты" << endl;
    }
};
int main() {
    Book myBook;
    Tape myTape;

    cout << "Введите данные о книге:" << endl;
    myBook.getdata();
    cout << "\nВведите данные аудиокниги:" << endl;
    myTape.getdata();

    cout << "\nДанные о книге:" << endl;
    myBook.putdata();
    cout << "\nДанные аудиокниги:" << endl;
    myTape.putdata();
    
    return 0;
}

