
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> words;
    string input;

    cout << "Введите слова по одному (для окончания введите 'end'):" << endl;

    while (true) {
        getline(cin, input);
        if (input == "end") {
            break;
        }
        if (!input.empty()) {
            words.push_back(input);
        }
    }

    sort(words.begin(), words.end());

    cout << "\nОтсортированные слова:\n";
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}


