#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;
class Fraction {
private:
    int chis;   
    int znam; 
    void lowterms() {
        long tnum, tden, temp, gcd;
        tnum = labs(chis); 
        tden = labs(znam);
        if (tden == 0) {
            cout << "Недопустимый знаменатель!";
            exit(1);
        }
        else if (tnum == 0) {
            chis = 0;
            znam = 1;
            return;
        }
        while (tnum != 0) {
            if (tnum < tden) { 
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden; 
        }
        gcd = tden;
        chis = chis / gcd;
        znam = znam / gcd;
    }
public:
    Fraction() : chis(0), znam(1) {}
    Fraction(int n, int d) : chis(n), znam(d) {
        lowterms();
    }
    void showFraction() const {
        cout << chis << "/" << znam;
    }
    Fraction multiply(const Fraction& f) const {
        int num = chis * f.chis;
        int den = znam * f.znam;
        return Fraction(num, den);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int den;
    cout << "Введите знаменатель: ";
    cin >> den;
    vector<Fraction> fractions;
    for (int i = 1; i < den; ++i) {
        fractions.push_back(Fraction(i, den));
    }
    for (const auto& frac : fractions) {
        frac.showFraction();
        cout << "    ";
    }
    cout << endl << "-----------------------------------------" << endl;
    for (const auto& frac1 : fractions) {
        frac1.showFraction();
        cout << "  ";
        for (const auto& frac2 : fractions) {
            Fraction result = frac1.multiply(frac2);
            result.showFraction();
            cout << "  ";
        }
        cout << endl;
    }

    return 0;
}
