#include <iostream>

struct Beka {
    int pounds;
    int shillings;
    int pence;
};

// Прототипы функций
Beka getBeka();
Beka addBeka(const Beka& s1, const Beka& s2);
void displayBeka(const Beka& s);

int main() {
    Beka s1 = getBeka();
    Beka s2 = getBeka();
    Beka sum = addBeka(s1, s2);
    displayBeka(sum);
    return 0;
}

// Определения функций
Beka getBeka() {
    Beka s;
    std::cout << "Введите сумму (фунты, шиллинги, пенсы): ";
    std::cin >> s.pounds >> s.shillings >> s.pence;
    return s;
}

Beka addBeka(const Beka& s1, const Beka& s2) {
    Beka sum;
    int total_pence = (s1.pounds * 240 + s1.shillings * 12 + s1.pence) +
                      (s2.pounds * 240 + s2.shillings * 12 + s2.pence);
    sum.pounds = total_pence / 240;
    total_pence %= 240;
    sum.shillings = total_pence / 12;
    sum.pence = total_pence % 12;
    return sum;
}

void displayBeka(const Beka& s) {
    std::cout << "Сумма: " << s.pounds << "£ " << s.shillings << "s " << s.pence << "p" << std::endl;
}
