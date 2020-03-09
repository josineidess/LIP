#include <iostream>

using namespace std;
int menor1;
int menor2;
int n;
int vezes=0;
int main() {
    do{
     cin >> n;
     if(vezes==0 && n!= 0){
         menor1 = n;
     }
     else if(vezes == 1 && n!=0){
         if(n < menor1){
             menor2=menor1;
             menor1 = n;
         }else{
             menor2 = n;
         }
     }
     else{
         if((n < menor1 || n < menor2)&& n!= 0){
             if(n < menor1){
                 menor2 = menor1;
                 menor1=n;
             }else{
                 menor2=n;
             }
            }
         }
    vezes++;
    }while(n!=0);
    cout << menor1 << " " << menor2;
    return 0; 
}
