#include <iostream>

using namespace std;
int pares=0;
int impares=0;
int num;
int main() {
    do{
     cin >> num;
     if(num%2==0){
         pares+=num;
     }else{
         if(num > 0){
         impares+=num;
         }
     }
    }while(num >= 0);
    cout << "Soma dos pares: " << pares << "\nSoma dos impares: " << impares;
    return 0;
}
