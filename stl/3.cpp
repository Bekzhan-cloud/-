#include <iostream>
#include <list>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    list<int> theList;

    for (int j = 2; j < 16; j += 2) {
        theList.push_back(j);
    }

    cout << "До переворачивания: ";
    for (auto iter = theList.begin(); iter != theList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << "\n";
    auto iter1 = theList.begin();
    auto iter2 = theList.end();
    --iter2;

    while (iter1 != iter2 && next(iter1) != iter2) {
        swap(*iter1, *iter2);
        ++iter1;
        --iter2;
    }

    cout << "После переворачивания: ";
    for (auto iter = theList.begin(); iter != theList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << "\n";

    return 0;
}
