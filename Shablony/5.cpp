#include <iostream>
#include <stdexcept>  // Для стандартных исключений
using namespace std;

const int LIMIT = 100;  // Размер массива

// Класс исключения для выхода за пределы массива
class IndexOutOfRangeException : public runtime_error {
public:
    // Конструктор, который вызывает родительский конструктор
    IndexOutOfRangeException(const string& msg)
        : runtime_error(msg) {}
};

class safearray {
private:
    int arr[LIMIT];

public:
    // Установка значения элемента массива
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException("Ошибка: Индекс выходит за пределы массива!");
        }
        arr[n] = elvalue;
    }

    // Получение значения элемента массива
    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException("Ошибка: Индекс выходит за пределы массива!");
        }
        return arr[n];
    }
};

int main() {
    safearray sa1;

    try {
        // Задаем значения элементов
        for (int j = 0; j < LIMIT; j++) {
            sa1.putel(j, j * 10);
        }

        // Показываем элементы
        for (int j = 0; j < LIMIT; j++) {
            int temp = sa1.getel(j);
            cout << "Элемент " << j << " равен " << temp << endl;
        }

        // Пример ошибки: выход за пределы массива
        sa1.putel(150, 500); // Генерируется исключение

    }
    catch (const IndexOutOfRangeException& e) {
        cout << "Ошибка: " << e.what() << endl;  // Обработка исключения
    }

    return 0;
}
