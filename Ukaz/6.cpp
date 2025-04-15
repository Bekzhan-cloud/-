// 6.cpp :
#include <iostream>
using namespace std;

int comp(char* a, char* b) {
    while (*a && *b) {
        if (*a < *b) return -1;
        if (*a > *b) return 1;
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0') return 0;
    if (*a == '\0') return -1;
    return 1;
}

int main() {
    char* x = (char*)"apple";
    char* y = (char*)"banana";
    char* z = (char*)"apple";

    cout << comp(x, y) << endl; // -1
    cout << comp(y, x) << endl; // 1
    cout << comp(x, z) << endl; // 0

    return 0;
}
