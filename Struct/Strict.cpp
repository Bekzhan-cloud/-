#include <iostream>
using namespace std;

struct beka_phone {
    int areaCode;
    int exchange;
    int number;
};

int main() {
    beka_phone myNumber = {212, 767, 8900};
    beka_phone userNumber;
    
    cout << "Введите код города, номер станции и номер абонента: ";
    cin >> userNumber.areaCode >> userNumber.exchange >> userNumber.number;
    
    cout << "Мой номер: (" << myNumber.areaCode << ") " << myNumber.exchange << "-" << myNumber.number << endl;
    cout << "Ваш номер: (" << userNumber.areaCode << ") " << userNumber.exchange << "-" << userNumber.number << endl;
    
    return 0;
}

