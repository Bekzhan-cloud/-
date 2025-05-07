#include <iostream>
#include <stdexcept>  // ��� ����������� ����������
#include <sstream>    // ��� �������� ����� � �����������
using namespace std;

const int LIMIT = 10;  // ������ �������

// ����� ���������� ��� ������ �� ������� �������
class IndexOutOfRangeException : public runtime_error {
public:
    // �����������, ������� ��������� ������ � ������� ��������� �� ������
    IndexOutOfRangeException(int index)
        : runtime_error(createMessage(index)) {}

private:
    // ������� ��� �������� ��������� �� ������
    static string createMessage(int index) {
        stringstream ss;
        ss << "������: ������ " << index << " ������� �� ������� �������!";
        return ss.str();
    }
};

class safearray {
private:
    int arr[LIMIT];

public:
    // ��������� �������� �������� �������
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException(n);  // ���������� ���������� � ��������
        }
        arr[n] = elvalue;
    }

    // ��������� �������� �������� �������
    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException(n);  // ���������� ���������� � ��������
        }
        return arr[n];
    }
};

int main() {
    safearray sa1;

    try {
        // ������ �������� ���������
        for (int j = 0; j < LIMIT; j++) {
            sa1.putel(j, j * 10);
        }

        // ���������� ��������
        for (int j = 0; j < LIMIT; j++) {
            int temp = sa1.getel(j);
            cout << "������� " << j << " ����� " << temp << endl;
        }

        // ������ ������: ����� �� ������� �������
        sa1.putel(150, 500); // ������������ ����������

    }
    catch (const IndexOutOfRangeException& e) {
        cout << e.what() << endl;  // ��������� ���������� � ����� ������ � ��������
    }

    return 0;
}
