#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float vetor[2][1],dx,dy,graus;
char entrada;
int cont = 2;
double transformacoes[30];

void transladar(float vetor[2][1],double transformacoes[],float& dx,float& dy,int& cont);
void rotacao(float vetor[2][1],double transformacoes[],float graus,int& cont);
bool botaVirgula(int e);

int main() {
    for(int e = 0;e < 2;e++){
        for(int i = 0;i < 1;i++){
            cin >> vetor[e][i];
            transformacoes[e] = vetor[e][i];
        }
    }
    do{
        cin >> entrada;
        if(entrada == 't'){
            cin >> dx;
            cin >> dy;
            transladar(vetor,transformacoes,dx,dy,cont);            
        }else if(entrada == 'r'){
            cin >> graus;
            rotacao(vetor,transformacoes,graus,cont);
        }
        
    }while(entrada!= 'f');
    cout << "( ";

    for(int e = 0;e < cont;e++){
        if(e%2 == 0 && e != 0){
            cout << " ) -> ( ";
            cout << fixed << setprecision(2) <<transformacoes[e];
            if(botaVirgula(e)){
               cout << " , ";
            }
        }else{
            cout << fixed << setprecision(2) <<transformacoes[e];
             if(botaVirgula(e)){
               cout << " , ";
            }
        }
    }
    cout << " )" << endl;
    return 0;
}

bool botaVirgula(int e){
    if((e+1)%2 == 0){
        return false;
    }else{
        return true;
    }
}


void transladar(float vetor[2][1],double transformacoes[],float& dx,float& dy,int& cont){
    transformacoes[cont] = vetor[0][0] + dx;
    vetor[0][0] = transformacoes[cont];
    cont++;
    transformacoes[cont] = vetor[1][0] + dy;
    vetor[1][0] = transformacoes[cont];
    cont++;
}

void rotacao(float vetor[2][1],double transformacoes[],float graus,int& cont){
    double mat_M[2][2];
    double radianos = graus * (M_PI/180);
    mat_M[0][0] = cos(radianos);
    mat_M[0][1] = sin(radianos);
    mat_M[1][0] = -sin(radianos);
    mat_M[1][1] = cos(radianos);
    
    transformacoes[cont] = (mat_M[0][0] * vetor[0][0]) + (mat_M[0][1] * vetor[1][0]);
    cont ++;
    transformacoes[cont] = (mat_M[1][0] * vetor[0][0]) + (mat_M[1][1] * vetor[1][0]);
    cont++;
    vetor[0][0] = transformacoes[cont-2];
    vetor[1][0] = transformacoes[cont-1];
    
}
     
