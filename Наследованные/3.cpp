#include <iostream>
#include <string>
using namespace std;

class Publication {
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

class Sales {
protected:
    float sales[3];
public:
    void getdata() {
        cout << "Введите продажи за последние 3 месяца: ";
        for (int i = 0; i < 3; i++) {
            cin >> sales[i];
        }
    }
    void putdata() const {
        cout << "Продажи за последние 3 месяца: ";
        for (int i = 0; i < 3; i++) {
            cout << sales[i] << " USD ";
        }
        cout << endl;
    }
};

class Book : public Publication, public Sales {
private:
    int page_count;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        Sales::getdata();
    }
    void putdata() const {
        Publication::putdata();
        cout << "Страницы: " << page_count << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
private:
    float play_time;
public:
    void getdata() {
        Publication::getdata();
        cout << "Введите продолжительность записи (в минутах): ";
        cin >> play_time;
        Sales::getdata();
    }
    void putdata() const {
        Publication::putdata();
        cout << "Время воспроизведения: " << play_time << " minutes" << endl;
        Sales::putdata();
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "Введите данные для книги:" << endl;
    myBook.getdata();
    cout << "\nВведите данные для аудиозаписи:" << endl;
    myTape.getdata();

    cout << "\nДанные о книге:" << endl;
    myBook.putdata();
    cout << "\nДанные об аудиозаписи:" << endl;
    myTape.putdata();
    
    return 0;
}

