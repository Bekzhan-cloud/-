#include <iostream>
using namespace std;

struct beka_time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    beka_time t1;
    cout << "Введите время (часы, минуты, секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    long totalSecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    cout << "Общее количество секунд: " << totalSecs << endl;

    return 0;
}
