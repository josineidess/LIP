#include <iostream>

using namespace std;

int mat[30][30];
bool comparar(int elem,int l,int matriz[30][30],int c);
bool linha(int matriz_linha[],int matriz[30][30],int l,int c);
bool repete(int matriz[30][30],int l,int c);

int main() {
    int l,c;
    cin >> l;
    cin >> c;
    
    for(int e = 0; e < l;e++){
        for(int i = 0; i < c;i++){
            cin >> mat[e][i];
        }
    }
  
    if(repete(mat,l,c)){
        cout << "A matriz tem linhas repetidas" << endl;
    }else{
        cout << "A matriz nao tem linhas repetidase" << endl;
    }
    return 0;
}

bool comparar(int elem,int l,int matriz[30][30],int c){
    for(int e = 0;e < c;e++){
        for(int i = 0;i < c;i++){
            if((elem == matriz[e][i]) && e != l){
                return true;
            }
        }
    }
    return false;
}

bool linha(int matriz_linha[],int matriz[30][30],int l,int c){
     int cont = 0;
     for(int e = 0;e < c;e++){
         if(comparar(matriz_linha[e],l,matriz,c)){
             cont++;
         }
     }
     if(cont == c){ 
         return true;
     }else{
         return false;
     }
}

bool repete(int matriz[30][30],int l,int c){
    int matriz_linha[30];
    int k=0,ll = 0;
    for(int e = 0;e < l;e++){
        for(int i = 0; i < c;i++){
            matriz_linha[k] = matriz[e][i];
            k++;
        }
        if(linha(matriz_linha,matriz,ll,c)){
            return true;
        }else{
            k=0;
            ll++;
        }
    }
    return false;
}
