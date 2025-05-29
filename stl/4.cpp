#include <iostream>
#include <set>
#include <string>
#include <Windows.h>
using namespace std;

class Penguin {
private:
    string lastName;
    string firstName;
    long phoneNumber;

public:
    Penguin() : lastName("пусто"), firstName("пусто"), phoneNumber(0L) {}
    Penguin(const string& lana, const string& fina, long pho)
        : lastName(lana), firstName(fina), phoneNumber(pho) {}

   
    bool isLessThan(const Penguin& other) const {
        if (lastName == other.lastName)
            return firstName < other.firstName;
        return lastName < other.lastName;
    }

    void display() const {
        cout << endl << lastName << ",\t" << firstName << "\tТелефон: 0" << phoneNumber;
    }
};

class ComparePenguins {
public:
    bool operator()(const Penguin* lhs, const Penguin* rhs) const {
        return lhs->isLessThan(*rhs);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    multiset<Penguin*, ComparePenguins> penguinSet;

    
    penguinSet.insert(new Penguin("Шкиппер", "Лидер", 911000001));
    penguinSet.insert(new Penguin("Ковальски", "Умник", 911000002));
    penguinSet.insert(new Penguin("Рико", "Эксперт", 911000003));
    penguinSet.insert(new Penguin("Прапор", "Рядовой", 911000004));
    penguinSet.insert(new Penguin("Скиппер", "Лидер", 911000001));

    cout << "\n\nМножество упорядочено при создании:";
    for (const auto& p : penguinSet)
        p->display();

    
    for (auto it = penguinSet.begin(); it != penguinSet.end();) {
        delete* it;
        it = penguinSet.erase(it);
    }

    cout << endl;
    return 0;
}
