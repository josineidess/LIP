#include <iostream>

using namespace std;

int vezes = 2;
bool primo = true;
int n;
int main() {
    cin >> n;
    while(vezes < n){
        if(n%vezes==0){
            primo=false;
        }
    vezes++;
    }
    if(primo){
        cout << n << " é primo";
    }else{
        cout << n << " não é primo";
    }
    return 0;
}
