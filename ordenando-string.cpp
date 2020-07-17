#include <iostream>

#define TAM 100

using namespace std;

void separa_vogal_cons(char letras[],int t,char vogais[],char consoantes[]);
void transforma_em_int(char letras_char[],int t,int letras_int[]);
void ordena_alfab(int letras[],int t);

int main() {
    char letras[TAM],vogais[TAM],consoantes[TAM];
    int tam_l=0,e = 0;
    
    cin >> letras;
    
    while(letras[e] != '\0'){
        e++;
        tam_l++;
    }
    tam_l++;
    
    cout << letras << endl;
    separa_vogal_cons(letras,tam_l,vogais,consoantes);
    cout << letras << endl;
    
    return 0;
}

void separa_vogal_cons(char letras[],int t,char vogais[],char consoantes[]){
    int quantv=0,quantc=0,contv=0,contc=0;
    
    for(int e = 0;e < t;e++){
        if(letras[e] == 'a' || letras[e] == 'e' || letras[e] == 'i' || letras[e] == 'o' || letras[e] == 'u'){
            vogais[contv] = letras[e];
            quantv++;
            contv++;
        }else{
            consoantes[contc] = letras[e];
            quantc++;
            contc++;
        }
    }
   
    vogais[contv] = '\0';
    contc--;
    
    int cons_int[contc],vog_int[contv];
    transforma_em_int(vogais,contv,vog_int);
    transforma_em_int(consoantes,contc,cons_int);
    ordena_alfab(cons_int,contc);
    ordena_alfab(vog_int,contv);
    
    for(int e = 0;e < contv;e++){
        letras[e] = char(vog_int[e]);
    }
    
    for(int e = contv,k=0;k < contc;k++,e++){
        letras[e] = char(cons_int[k]);
    }
}


void transforma_em_int(char letras_char[],int t,int letras_int[]){
    for(int e = 0;e < t;e++){
        letras_int[e] = int(letras_char[e]);
    }    
}

void ordena_alfab(int letras[],int t){
    int ant;
    for(int e = t-1;e >= 1;e--){
      for(int i = 0;i < e;i++){
          if(letras[i] > letras[i +1 ]){
              ant = letras[i + 1];
              letras[i + 1] = letras[i];
              letras[i] = ant;
          }
      }
  }
}
