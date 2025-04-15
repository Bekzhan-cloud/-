#include <iostream>
using namespace std;

struct link
{
    int data;
    link* next;
};

class linklist
{
private:
    link* first;

public:
    linklist() : first(nullptr) {}

    void additem(int d)
    {
        link* newlink = new link;
        newlink->data = d;
        newlink->next = nullptr;

        if (first == nullptr)
        {
            first = newlink;
        }
        else
        {
            link* current = first;
            while (current->next)
                current = current->next;
            current->next = newlink;
        }
    }

    void display()
    {
        link* current = first;
        while (current)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    ~linklist()
    {
        link* current = first;
        int count = 0;
        while (current)
        {
            link* temp = current;
            cout << "Удаление: " << temp->data << endl;
            current = current->next;
            delete temp;
            count++;
        }
        cout << "Удалено элементов: " << count << endl;
        cout << "Готово." << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    linklist li;

    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();

    return 0;
}
