#include <iostream>
using namespace std;

const int NUMARRAYS = 10;
const int MAXSIZE = 10;

class ArrayWrapper
{
private:
    int* ap[NUMARRAYS];

public:
    ArrayWrapper()
    {
        for (int j = 0; j < NUMARRAYS; ++j)
        {
            ap[j] = new int[MAXSIZE];
        }
        cout << "Конструктор: Память выделена для 10 массивов по 10 элементов." << endl;
    }

    ~ArrayWrapper()
    {
        for (int j = 0; j < NUMARRAYS; ++j)
        {
            delete[] ap[j];
        }
        cout << "Деструктор: Память освобождена для всех массивов." << endl;
    }

    int& operator[](int index)
    {
        int j = index / MAXSIZE;
        int k = index % MAXSIZE;
        return ap[j][k];
    }

    void display() const
    {
        cout << ": Выводим содержимое всех массивов." << endl;
        for (int j = 0; j < NUMARRAYS; ++j)
        {
            for (int k = 0; k < MAXSIZE; ++k)
            {
                cout << ap[j][k] << " ";
            }
            cout << endl;
        }
    }

    int* getArray(int j) const
    {
        return ap[j];
    }
};

ostream& operator<<(ostream& os, const ArrayWrapper& a)
{
    cout << "Перегрузка оператора <<: Выводим содержимое всех массивов через перегруженный оператор." << endl;
    for (int j = 0; j < NUMARRAYS; ++j)
    {
        for (int k = 0; k < MAXSIZE; ++k)
        {
            os << a.getArray(j)[k] << " ";
        }
        os << endl;
    }
    return os;
}

int main()
{
    setlocale(LC_ALL, "ru");

    ArrayWrapper a;
    cout << "Создан объект класса ArrayWrapper." << endl;

    int value = 0;
    for (int i = 0; i < NUMARRAYS * MAXSIZE; ++i)
    {
        a[i] = value;
        value += 10;
    }

    cout << "Выводим все элементы массивов." << endl;
    cout << a;

    return 0;
}
