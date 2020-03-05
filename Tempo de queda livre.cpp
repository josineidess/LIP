#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float h0;
float tempo;
int main(){
    cin >> h0;
    tempo = sqrt((-h0/(-9.8/2)));
    cout << setprecision(2) << fixed;
    cout << tempo;
    return 0;
}

