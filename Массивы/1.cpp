#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

void reversit(char str[]) {
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX = 2000;
    char str[MAX];
    cout << "Введите строку (закончите ввод символом $):\n";
    cin.get(str, MAX, '$');
    reversit(str);
    cout << "Перевернутая строка: " << str << endl;
    return 0;
}

