#include <iostream>

struct Beka {
    int numerator;
    int denominator;
};

// Прототипы функций
Beka fadd(const Beka& f1, const Beka& f2);
Beka fsub(const Beka& f1, const Beka& f2);
Beka fmul(const Beka& f1, const Beka& f2);
Beka fdiv(const Beka& f1, const Beka& f2);

int main() {
    Beka f1 = {1, 2}, f2 = {3, 4};
    Beka result = fadd(f1, f2);
    std::cout << "Сумма: " << result.numerator << "/" << result.denominator << std::endl;
    return 0;
}

// Определения функций
Beka fadd(const Beka& f1, const Beka& f2) {
    Beka result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

Beka fsub(const Beka& f1, const Beka& f2) {
    Beka result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

Beka fmul(const Beka& f1, const Beka& f2) {
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

Beka fdiv(const Beka& f1, const Beka& f2) {
    return { f1.numerator * f2.denominator, f1.denominator * f2.numerator };
}
