// 5.cpp :
#include <iostream>
using namespace std;

void add(float* a, float* b, float* c, int n) {
    for (int i = 0; i < n; i++)
        *(c + i) = *(a + i) + *(b + i);
}

int main() {
    const int n = 5;
    float x[n] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    float y[n] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
    float z[n];

    add(x, y, z, n);

    for (int i = 0; i < n; i++)
        cout << *(z + i) << " ";
    cout << endl;

    return 0;
}
