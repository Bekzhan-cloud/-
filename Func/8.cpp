#include <iostream>

// Прототип функции
void swap(int& a, int& b);

int main() {
    int x = 5, y = 10;
    std::cout << "До swap: x = " << x << ", y = " << y << std::endl;
    
    swap(x, y);
    
    std::cout << "После swap: x = " << x << ", y = " << y << std::endl;
    return 0;
}

// Определение функции
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
