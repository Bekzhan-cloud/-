#include <iostream>
using namespace std;

struct beka_time {
    int hours;
    int minutes;
    int seconds;
};

int toSeconds(beka_time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

beka_time fromSeconds(int totalSecs) {
    beka_time t;
    t.hours = totalSecs / 3600;
    t.minutes = (totalSecs % 3600) / 60;
    t.seconds = totalSecs % 60;
    return t;
}

int main() {
    beka_time t1, t2, sum;

    cout << "Введите первое время (часы, минуты, секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;
    cout << "Введите второе время (часы, минуты, секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    int totalSecs = toSeconds(t1) + toSeconds(t2);
    sum = fromSeconds(totalSecs);

    cout << "Сумма времен: " << sum.hours << ":" << sum.minutes << ":" << sum.seconds << endl;

    return 0;
}
