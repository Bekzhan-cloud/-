#include <iostream>
#include <stdexcept>  // ��� ����������� ����������
using namespace std;

const int LIMIT = 100;  // ������ �������

// ����� ���������� ��� ������ �� ������� �������
class IndexOutOfRangeException : public runtime_error {
public:
    // �����������, ������� �������� ������������ �����������
    IndexOutOfRangeException(const string& msg)
        : runtime_error(msg) {}
};

class safearray {
private:
    int arr[LIMIT];

public:
    // ��������� �������� �������� �������
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException("������: ������ ������� �� ������� �������!");
        }
        arr[n] = elvalue;
    }

    // ��������� �������� �������� �������
    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException("������: ������ ������� �� ������� �������!");
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
        cout << "������: " << e.what() << endl;  // ��������� ����������
    }

    return 0;
}
