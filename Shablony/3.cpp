#include <iostream>
using namespace std;

const int LIMIT = 100;

template <typename T>
class SafeArray {
private:
    T arr[LIMIT];

public:
    T& operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "\n��������� ������! ������ ������ ���� � �������� �� 0 �� " << LIMIT - 1 << ".\n";
            return arr[0];
        }
        return arr[n];
    }

    void fill() {
        for (int j = 0; j < LIMIT; j++) {
            arr[j] = j * 10;
        }
    }

    void show() {
        for (int j = 0; j < LIMIT; j++) {
            cout << "������� " << j << " ����� " << arr[j] << endl;
        }
    }
};

int main() {
    int choice;

    cout << "�������� ��� �������:\n1. int\n2. float\n0. �����\n��� �����: ";
    cin >> choice;

    switch (choice) {
    case 1:
    {
        SafeArray<int> sa1;
        sa1.fill();
        sa1.show();
        break;
    }
    case 2:
    {
        SafeArray<float> sa2;
        sa2.fill();
        sa2.show();
        break;
    }
    case 0:
        cout << "����� �� ���������...\n";
        break;
    default:
        cout << "�������� �����.\n";
        break;
    }

    return 0;
}
