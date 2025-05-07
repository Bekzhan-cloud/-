#include <iostream>
using namespace std;


template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== ���� swaps() ===\n";
        cout << "1 - �������� ��� int\n";
        cout << "2 - �������� ��� float\n";
        cout << "3 - �������� ��� char\n";
        cout << "0 - �����\n";
        cout << "�������� �������: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "�������� ����. ���������� �����.\n";
            continue;
        }

        if (choice == 1) {
            int a, b;
            cout << "������� ��� ����� �����: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "����� swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 2) {
            float a, b;
            cout << "������� ��� ����� � ��������� ������: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "����� swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 3) {
            char a, b;
            cout << "������� ��� �������: ";
            cin >> a >> b;
            swaps(a, b);
            cout << "����� swaps: a = " << a << ", b = " << b << endl;
        }
        else if (choice == 0) {
            cout << "����� �� ���������.\n";
            break;
        }
        else {
            cout << "�������� �����.\n";
        }
    }

    return 0;
}
