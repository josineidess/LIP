
#include <iostream>

using namespace std;

int sequencia(int n);
int somatorio(int n);
int n;

int main() {
    cin >> n;
    cout << somatorio(n) << endl;
    return 0;
}

int sequencia(int n){
   if(n == 0 || n == 1){
       if(n == 0){
           return 5;
       }else{
           return 7;
       }
   }else{
       int a0 = 5;
       int a1 = 7;
       int an;
       for(int e = 2;e <= n;e++){
           an = 3 * a1 + 2* a0;
           a0 = a1;
           a1 = an;
       }
       return an;
   }
    
}

int somatorio(int n){
    int soma = 12;
    if(n == 0 || n == 1){
        if(n == 0){
            return 5;
        }else{
            return 12;
        }
    }else{
        for(int e = 2;e<= n;e++){
            soma+= sequencia(e);
        }
        return soma;
    }
}
