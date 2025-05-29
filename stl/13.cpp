#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;

string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (!ispunct(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << "Файл не найден, создаю пустой файл с именем " << filename << endl;
        ofstream newFile(filename);
        newFile.close();
        cout << "Пустой файл создан. Запустите программу снова для подсчёта слов." << endl;
        return 0;
    }

    map<string, int> wordFrequency;
    string word;

    while (file >> word) {
        word = cleanWord(word);
        if (!word.empty())
            wordFrequency[word]++;
    }

    cout << "\nЧастотная таблица слов:\n";
    for (auto pair : wordFrequency)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
