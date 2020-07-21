#include <iostream>

using namespace std;
int sequencia(int n);

int main() {
    int n;
    cin >> n;
    cout << "a" << n << " = "<<sequencia(n) << endl;
    return 0;
}

int sequencia(int n){
    if(n == 1 || n == 2){
        if(n == 1){
            return 2;
        }else{
            return 3;
        }
    }else{
        return 2 * sequencia(n-2) + sequencia(n-1); 
    }
}
