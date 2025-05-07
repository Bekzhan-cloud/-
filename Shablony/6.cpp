#include <iostream>
#include <stdexcept>  // Для стандартных исключений
#include <sstream>    // Для создания строк с параметрами
using namespace std;

const int LIMIT = 10;  // Размер массива

// Класс исключения для выхода за пределы массива
class IndexOutOfRangeException : public runtime_error {
public:
    // Конструктор, который принимает индекс и создает сообщение об ошибке
    IndexOutOfRangeException(int index)
        : runtime_error(createMessage(index)) {}

private:
    // Функция для создания сообщения об ошибке
    static string createMessage(int index) {
        stringstream ss;
        ss << "Ошибка: Индекс " << index << " выходит за пределы массива!";
        return ss.str();
    }
};

class safearray {
private:
    int arr[LIMIT];

public:
    // Установка значения элемента массива
    void putel(int n, int elvalue) {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException(n);  // Генерируем исключение с индексом
        }
        arr[n] = elvalue;
    }

    // Получение значения элемента массива
    int getel(int n) const {
        if (n < 0 || n >= LIMIT) {
            throw IndexOutOfRangeException(n);  // Генерируем исключение с индексом
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
        cout << e.what() << endl;  // Обработка исключения и вывод ошибки с индексом
    }

    return 0;
}
