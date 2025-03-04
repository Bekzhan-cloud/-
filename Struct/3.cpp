#include <iostream>
using namespace std;

struct beka_Distance {
    int feet;
    float inches;
};

struct beka_Volume {
    beka_Distance length, width, height;
};

int main() {
    beka_Volume room = {{10, 0}, {12, 6}, {8, 3}};

    float l = room.length.feet + room.length.inches / 12.0;
    float w = room.width.feet + room.width.inches / 12.0;
    float h = room.height.feet + room.height.inches / 12.0;

    cout << "Объем помещения: " << (l * w * h) << " куб. футов" << endl;
    
    return 0;
}
