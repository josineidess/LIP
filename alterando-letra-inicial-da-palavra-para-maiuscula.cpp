#include <iostream>
#include <ctype.h>

using namespace std;

void maisculas(char frase[],int tam);

int main() {
    char frase[100];
    cin.getline(frase,100);
    
    int tam=0,e=0;
    while(frase[e] != '\0'){
        tam++;
        e++;
    }
    maisculas(frase,tam);
    
    for(int e = 0;e < tam;e++){
        cout << frase[e];
    }
    return 0;
}

void maisculas(char frase[],int tam){
    for(int e = 0;e < tam+1;e++){
        if(e == 0){
            if(frase[0] != ' '){
                frase[0] = toupper(frase[0]);
            }
        }else{
           if(frase[e-1] == ' '){
            frase[e] = toupper(frase[e]);
           } 
        }
    }
}
