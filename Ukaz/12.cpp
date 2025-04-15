// 12.cpp :
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
float fmemory[MAX_SIZE];  
int pmemory[MAX_SIZE];    

int fmem_top = 0;  
int pmem_top = 0;  

class Float {
public:
    int addr;  

   
    Float(float value) {
        addr = fmem_top;  
        fmemory[fmem_top] = value;  
        fmem_top++;  


    
    int& operator&() {
        return addr;
    }
};

class ptrFloat {
private:
    int addr;  

public:
    
    ptrFloat(int* p) {
        addr = pmem_top;  
        pmemory[pmem_top] = *p; 
        pmem_top++; 
    }

   
    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

int main() {
    setlocale(LC_ALL, "ru");

   
    Float var1(1.234);
    Float var2(5.678);

    
    ptrFloat ptr1(&var1.addr);
    ptrFloat ptr2(&var2.addr);

    
    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;

    
    *ptr1 = 7.123;
    *ptr2 = 8.456;

   
    cout << " *ptr1 = " << *ptr1 << endl;
    cout << " *ptr2 = " << *ptr2 << endl;

    return 0;
}

