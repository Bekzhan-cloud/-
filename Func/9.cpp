#include <iostream>

struct Beka {
    int hours;
    int minutes;
    int seconds;
};

// Прототип функции
void swap(Beka& t1, Beka& t2);

int main() {
    Beka t1 = {1, 30, 45};
    Beka t2 = {2, 15, 30};

    std::cout << "До swap: t1 = " << t1.hours << ":" << t1.minutes << ":" << t1.seconds
              << ", t2 = " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << std::endl;
    
    swap(t1, t2);
    
    std::cout << "После swap: t1 = " << t1.hours << ":" << t1.minutes << ":" << t1.seconds
              << ", t2 = " << t2.hours << ":" << t2.minutes << ":" << t2.seconds << std::endl;
    
    return 0;
}

// Определение функции
void swap(Beka& t1, Beka& t2) {
    Beka temp = t1;
    t1 = t2;
    t2 = temp;
}
