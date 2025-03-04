#include <iostream>
using namespace std;

enum beka_etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char ch;
    beka_etype empType;

    cout << "Введите первую букву должности (l, s, m, a, e, r): ";
    cin >> ch;

    switch (ch) {
        case 'l': empType = laborer; break;
        case 's': empType = secretary; break;
        case 'm': empType = manager; break;
        case 'a': empType = accountant; break;
        case 'e': empType = executive; break;
        case 'r': empType = researcher; break;
        default: cout << "Некорректный ввод"; return 1;
    }

    cout << "Полное название должности: ";
    switch (empType) {
        case laborer: cout << "laborer"; break;
        case secretary: cout << "secretary"; break;
        case manager: cout << "manager"; break;
        case accountant: cout << "accountant"; break;
        case executive: cout << "executive"; break;
        case researcher: cout << "researcher"; break;
    }

    return 0;
}
