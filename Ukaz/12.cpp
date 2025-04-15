// 12.cpp :
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
float fmemory[MAX_SIZE];  
int pmemory[MAX_SIZE];    

int fmem_top = 0;  
int pmem_top = 0;  

class Float {
public:
    int addr;  // Адрес в fmemory (индекс элемента массива fmemory)

    // Конструктор для инициализации значением типа float
    Float(float value) {
        addr = fmem_top;  // Получаем текущий адрес
        fmemory[fmem_top] = value;  // Сохраняем значение в fmemory
        fmem_top++;  // Инкрементируем указатель на следующий свободный элемент
    }

    // Перегрузка оператора & для возврата адреса (индекса)
    int& operator&() {
        return addr;
    }
};

class ptrFloat {
private:
    int addr;  // Адрес в pmemory (индекс элемента массива pmemory)

public:
    // Конструктор для инициализации указателем
    ptrFloat(int* p) {
        addr = pmem_top;  // Получаем текущий адрес
        pmemory[pmem_top] = *p;  // Сохраняем индекс переменной
        pmem_top++;  // Инкрементируем указатель на следующий свободный элемент
    }

    // Перегрузка оператора * для разыменования (получение значения по адресу)
    float& operator*() {
        return fmemory[pmemory[addr]];  // Получаем значение из fmemory по индексу
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Инициализация переменных типа Float
    Float var1(1.234);
    Float var2(5.678);

    // Инициализация указателей типа ptrFloat
    ptrFloat ptr1(&var1.addr);
    ptrFloat ptr2(&var2.addr);

    // Вывод значений через указатели
    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;

    // Присваивание новых значений через указатели
    *ptr1 = 7.123;
    *ptr2 = 8.456;

    // Снова выводим измененные значения
    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;

    return 0;
}

