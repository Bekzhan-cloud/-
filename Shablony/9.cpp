#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

class dofile {
private:
    fstream file;
    string filename;

public:
   
    class FileException : public runtime_error {
    public:
        FileException(const string& msg) : runtime_error(msg) {}
    };

    
    dofile(const string& fname) : filename(fname) {
        file.open(filename, ios::in | ios::out);
        if (!file) {
            throw FileException("������ ��� �������� �����: " + filename);
        }
    }

    
    void readFile() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    
    void rewind() {
        file.clear();             
        file.seekg(0, ios::beg);  
    }

    
    void writeToFile(const string& text) {
        file.clear();             
        file.seekp(0, ios::end);   
        file << text << endl;      
    }

    
    ~dofile() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    try {
        dofile df("test.txt");

        cout << "������ ����������� �����:\n";
        df.readFile();

        cout << "\n���������� ��������� � ������...\n";
        df.rewind();

        cout << "\n����� ������ ����:\n";
        df.readFile();

        cout << "\n���������� � ����:\n";
        df.writeToFile("����������� ������ � ����.");

    }
    catch (const dofile::FileException& e) {
        cerr << "������: " << e.what() << endl;
    }

    return 0;
}
