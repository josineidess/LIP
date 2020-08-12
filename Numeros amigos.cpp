#include <iostream>
using namespace std;

int n;
int soma_a=0,soma_b=0;
bool numero_amigo(int n);

int main() {
    cin >> n;
    for(int e = 1;e < n;e++){
    if(numero_amigo(e)){
        cout << soma_b << " amigo de " << soma_a << endl;
    }
    soma_a = 0;
    soma_b = 0;
    }
    return 0;
}

bool numero_amigo(int n) {
    int som_a = 0;
    int som_b = 0;
    for(int e = 1;e < n;e++){
        if(n % e == 0){
            som_a+=e;
        }
    }
    soma_a = som_a;
    for(int e = 1;e < som_a;e++){
        if(som_a % e == 0){
            som_b+=e;
        }
    }
    soma_b = som_b;
    if(n == soma_b){
        return true;
    }else{
        return false;
    }
}
