#include <iostream>

// Прототипы функций
void counterGlobal();
void counterStatic();

// Глобальная переменная
int globalCount = 0;

int main() {
    std::cout << "Глобальная переменная:\n";
    for (int i = 0; i < 10; ++i)
        counterGlobal();

    std::cout << "\nСтатическая переменная:\n";
    for (int i = 0; i < 10; ++i)
        counterStatic();
    
    return 0;
}

// Определение с глобальной переменной
void counterGlobal() {
    globalCount++;
    std::cout << "Функция вызвана " << globalCount << " раз(а)\n";
}

// Определение со статической переменной
void counterStatic() {
    static int staticCount = 0;
    staticCount++;
    std::cout << "Функция вызвана " << staticCount << " раз(а)\n";
}
