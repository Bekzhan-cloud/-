#include <iostream>
using namespace std;


template <typename T>
T amax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== ���� amax() ===\n";
        cout << "1 - ����� �������� � int-�������\n";
        cout << "2 - ����� �������� � float-�������\n";
        cout << "3 - ����� �������� � char-�������\n";
        cout << "0 - �����\n";
        cout << "�������� �������: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������ �����. ���������� �����.\n";
            continue;
        }

        if (choice == 0) {
            cout << "����� �� ���������.\n";
            break;
        }

        int size;
        cout << "������� ������ �������: ";
        cin >> size;

        if (size <= 0 || cin.fail()) {
            cout << "�������� ������ �������. ���������� �����.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            int* arr = new int[size];
            cout << "������� " << size << " ����� �����:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "��������: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else if (choice == 2) {
            float* arr = new float[size];
            cout << "������� " << size << " ����� � ��������� ������:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "��������: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else if (choice == 3) {
            char* arr = new char[size];
            cout << "������� " << size << " ��������:\n";
            for (int i = 0; i < size; ++i) {
                cin >> arr[i];
            }
            cout << "��������: " << amax(arr, size) << endl;
            delete[] arr;
        }
        else {
            cout << "�������� �����. ���������� �����.\n";
        }
    }

    return 0;
}
