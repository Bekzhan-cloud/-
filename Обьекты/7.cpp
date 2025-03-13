#include <iostream>
using namespace std;
class MyClass {
private:
    static int count; 
    int num; 
public:
    MyClass() {
        count++;
        num = count;
    }
    void displaySerialNumber() const {
        cout << "Мой порядковый номер: " << num << endl;
    }
};
int MyClass::count = 0;
int main() {
    setlocale(LC_ALL, "rus");
    const int n = 10;
    MyClass obj[n];
    for (int i = 0; i < n; i++) {
        obj[i].displaySerialNumber();
    }
    return 0;
}
