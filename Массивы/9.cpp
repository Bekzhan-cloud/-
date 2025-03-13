#include <iostream>
using namespace std;
class queue {
private:
    enum { MAX = 10 }; 
    int q[MAX];        
    int head;          // начало очереди
    int tail;          // конец очереди
    int count;         // количество элементов в очереди
public:
    queue() : head(0), tail(-1), count(0) {} 
    void put(int var) {
        if (count == MAX) {
            cout << "Переполнение очереди";
        }
        tail = (tail + 1) % MAX;
        q[tail] = var;
        ++count;
    }
    int get() {
        if (count == 0) {
            cout << "Очередь пуста";
        }
        int value = q[head];
        head = (head + 1) % MAX;
        --count;
        return value;
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    queue q1;
    int choice, value;
    while (true) {
        cout << "Выберите действие: \n1 - Добавить элемент в очередь\n2 - Извлечь элемент из очереди\n0 - Выйти: ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
        case 1:
            cout << "Введите значение для добавления в очередь: ";
            cin >> value;
            q1.put(value);
            break;
        case 2:
            value = q1.get();
            cout << "Извлеченное значение: " << value << endl;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
        }
    }
    return 0;
}

