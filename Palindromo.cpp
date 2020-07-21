#include <iostream>

#define TAM 100

using namespace std;

bool ehPalindromo(char str[],int ind_i,int ind_f);

int main(){
    char str[TAM];
    int tam_str=0,e=0;
    cin >> str;
    
    while(str[e] != '\0'){
        tam_str++;
        e++;
    }
    
    if(ehPalindromo(str,0,tam_str-1)){
        cout << str << " é palíndromo" << endl;
    }else{
        cout << str << " não é palíndromo" << endl;
    }
    return 0;
}

bool ehPalindromo(char str[],int ind_i,int ind_f){
    if(ind_i == ind_f || (str[ind_i - 1] == str[ind_f])){
        return true;
    }else{
        if(str[ind_i] != str[ind_f]){
            return false;
        }else{
          ind_f--;
          ind_i++;
          return ehPalindromo(str,ind_i,ind_f);
        }
    }
}
