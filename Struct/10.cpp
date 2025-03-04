#include <iostream>
using namespace std;

struct beka_sterling {
    int pounds;
    int shillings;
    int pence;
};

int main() {
    double decimalPounds;
    cout << "Введите сумму в десятичных фунтах: ";
    cin >> decimalPounds;

    beka_sterling oldMoney;
    oldMoney.pounds = static_cast<int>(decimalPounds);
    double fracPart = (decimalPounds - oldMoney.pounds) * 20;
    oldMoney.shillings = static_cast<int>(fracPart);
    oldMoney.pence = static_cast<int>((fracPart - oldMoney.shillings) * 12);

    cout << "Сумма в старой системе: " << oldMoney.pounds << " фунтов, "
         << oldMoney.shillings << " шиллингов, " << oldMoney.pence << " пенсов" << endl;

    return 0;
}
