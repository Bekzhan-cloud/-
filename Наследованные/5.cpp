#include <iostream> 
using namespace std;
const int LEN = 80; 
class employee {
private:
    char name[LEN];      
    unsigned long number; 
public:
    void getdata() {
        cout << "\n  Введите фамилию: "; cin >> name;
        cout << "  Введите номер: ";     cin >> number;
    }
    void putdata() const {
        cout << "\n  Фамилия: " << name;
        cout << "\n  Номер: " << number;
    }
};

class employee2 :public employee {
private:
    double compensation;
public:
    int t;
    void getdata() {
        employee::getdata();
        cout << "  Введите сумму оплаты: "; cin >> compensation;
        cout << "  Введите период оплаты (0 - почасовая, 1 - понедельная, 2 - помесячная): ";
    link:
        cin >> t;
        if (t > 2 || t < 0) {
            cout << "  Введите от 0 - 2!: "; goto link;
        }
    }
    void putdata() const {
        employee::putdata();
        cout << "  Оплата: " << compensation;
        cout << "  Период оплаты: ";
        switch (t) {
        case 0:cout << "почасовая"; break;
        case 1: cout << "понедельная"; break;
        case 2: cout << "помесячная"; break;
        }
    }
};
class manager : public employee2{
private:
    char title[LEN]; 
    double dues; 
public:
    void getdata() {
        employee2::getdata();
        cout << "  Введите должность: "; cin >> title;
        cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
    }
    void putdata() const {
        employee2::putdata();
        cout << "\n  Должность: " << title;
        cout << "\n  Сумма взносов в гольф-клуб: " << dues;
    }
};
class scientist : public employee2 {
private:
    int pubs;                   
public:
    void getdata() {
        employee2::getdata();
        cout << "  Введите количество публикаций: "; cin >> pubs;
    }
    void putdata() const {
        employee2::putdata();
        cout << "\n  Количество публикаций: " << pubs;
    }
};

class laborer :public employee2 {};
int main() {
    setlocale(LC_ALL, "rus");
    manager m1;
    scientist s1;
    laborer l1;
    cout << endl;
    cout << "Ввод информации о первом менеджере";
    m1.getdata();
    cout << "\nВвод информации о первом ученом";
    s1.getdata();
    cout << "\nВвод информации о первом рабочем";
    l1.getdata();
    cout << "\nИнформация о первом менеджере";
    m1.putdata();
    cout << "\n\nИнформация о первом ученом";
    s1.putdata();
    cout << "\n\nИнформация о первом рабочем";
    l1.putdata();
    cout << endl;
    return 0;
}
