
#include <iostream>

using namespace std;
int collatz(int n,int& passos);

int main()
{
    int passos = 0,n;
    
    cin >> n;
    collatz(n,passos);
    cout << "Números de passos: "<< passos << endl;

    return 0;
}

int collatz(int n,int& passos){
     cout << n << endl;
     if(n == 1){
         return n;
     }else{
         if(n%2 == 0){
             passos++;
             return collatz(n/2,passos);
         }else{
             passos++;
             return collatz((n*3)+1,passos);
         }
     }
}
