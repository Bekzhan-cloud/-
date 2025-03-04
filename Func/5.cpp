#include <iostream>
using namespace std;
long hms_to_secs(int h, int m, int s);


int main() {
    int h, m, s;
    cout << "Введите часы, минуты, секунды: ";
    cin >> h >> m >> s;
    cout << "Всего секунд: " << hms_to_secs(h, m, s) << endl;
    return 0;
}

long hms_to_secs(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
