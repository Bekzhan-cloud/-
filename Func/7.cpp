#include <iostream>

// Прототипы перегруженных функций
double power(double base, int exp = 2);
char power(char base, int exp = 2);
int power(int base, int exp = 2);
long power(long base, int exp = 2);
float power(float base, int exp = 2);

int main() {
    std::cout << "double: " << power(2.5, 3) << std::endl;
    std::cout << "char: " << power('A', 2) << std::endl; // Преобразуется в int
    std::cout << "int: " << power(3, 3) << std::endl;
    std::cout << "long: " << power(4L, 3) << std::endl;
    std::cout << "float: " << power(2.5f, 3) << std::endl;
    return 0;
}

// Определения функций
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

char power(char base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return static_cast<char>(result);
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

long power(long base, int exp) {
    long result = 1;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

float power(float base, int exp) {
    float result = 1.0f;
    for (int i = 0; i < exp; ++i)
        result *= base;
    return result;
}
