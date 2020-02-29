#include <iostream>
#include <cmath>

using namespace std;

int a,b,c,delta,nume1,raiz1,nume2,raiz2,den;

int main() {
    a = 1;
    b = 8;
    c = -9;
    delta = b*b - 4*a*c;
    den = 2*a;
    nume1 = -b + sqrt(delta);
    raiz1 = nume1/den;
    nume2 = -b - sqrt(delta);
    raiz2 = nume2/den;
    cout << raiz1 << " " << raiz2;
    return 0;
}
