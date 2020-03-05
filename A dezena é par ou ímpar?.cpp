#include <iostream>

using namespace std;
int n;

int main() {
    cin >> n;
    n = n%100;
    n =n - n%10;
    n = n/10;
    if(n%2==0){
        cout << "A dezena é par!";
    }else{
        cout << "A dezena é ímpar!";
    }
    return 0;
}
