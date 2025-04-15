#include <iostream>
using namespace std;
class timee {
private:
	int day;
	int month;
	int year;
public:
	timee() :day(0), month(0), year(0) {}
	timee(int d, int m, int y) :day(d), month(m), year(y) {}
	void getdata() {
		cout << "Введите день: "; cin >> day;
		cout << "Введите месяц: "; cin >> month;
		cout << "Введите год: "; cin >> year;
	}
	void print() {
		cout << (month < 10 ? "0" : "") << month << "/"
			<< (day < 10 ? "0" : "") << day << "/"
			<< year << endl;
	}
};
int main() {
	setlocale(LC_ALL, "rus");
	timee t;
	t.getdata();
	cout << "Дата: "; t.print();
	return 0;
}
