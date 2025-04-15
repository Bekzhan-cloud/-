// 9.cpp :
#include <iostream>
using namespace std;

int main()
{   
    setlocale(LC_ALL, "ru");
    const int n = 10; 
    int a0[n], a1[n], a2[n], a3[n], a4[n], a5[n], a6[n], a7[n], a8[n], a9[n];
    int* ap[10] = { a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 }; 


    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ap[i][j] = i * 10 + j; 
        }
    }


    for (int i = 0; i < 10; ++i)
    {
        cout << "Массив a" << i << ": ";
        for (int j = 0; j < n; ++j)
        {
            cout << ap[i][j] << " ";  
        }
        cout << endl;
    }

    return 0;
}
