#include <iostream>

struct Beka {
    int hours;
    int minutes;
    int seconds;
};

// Прототипы функций
long time_to_secs(const Beka& t);
Beka secs_to_time(long total_seconds);

int main() {
    Beka t1 = {1, 30, 45};
    Beka t2 = {2, 15, 30};

    long total_seconds = time_to_secs(t1) + time_to_secs(t2);
    Beka result = secs_to_time(total_seconds);

    std::cout << "Сумма времени: " << result.hours << "ч " 
              << result.minutes << "м " << result.seconds << "с" << std::endl;
    return 0;
}

// Определения функций
long time_to_secs(const Beka& t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Beka secs_to_time(long total_seconds) {
    Beka t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
}
