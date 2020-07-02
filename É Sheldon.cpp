#include <iostream>
#include <cmath>

using namespace std;

int n,pos=0,pos_invertido=0,pos_invertido_invertida=0,invertido,prod,bin,bin_invertido;


bool ehPrimo(int n);
void posicao(int n,int& posicao);
int digitos(int n);
int numero_invertido(int n,int& invertido);
void produto(int n,int& prod);
void binario(int n,int& bin);
bool ehPalindromo(int& b,int& n_i);
bool posi_igual_reverso(int& pos_invertido,int& pos_invertido_invertida);
bool ehSheldon(int n,int& invertido,int& pos_invertido,int& pos_invertido_invertida,int& pos,int& prod,int& bin,int& bin_invertido);

int main() {
    cin >> n;
    numero_invertido(n,invertido);
    posicao(n,pos);
    posicao(invertido,pos_invertido);
    produto(n,prod);
    binario(n,bin);
    numero_invertido(bin,bin_invertido);
    
    if(ehPrimo(n)){
        cout << "É primo" << endl;
    }else{
        cout << "Não é primo" << endl;
    }
    
    cout << "Posição: " << pos << endl;
    cout << "Número invertido: " << invertido << endl;
    
    if(ehPrimo(invertido)){
        cout << "Número invertido é primo" << endl;
    }else{
        cout << "Número invertido não é primo" << endl;
    }
    
    cout << "Posição número invertido: " << pos_invertido << endl;
    
    if(posi_igual_reverso(pos_invertido,pos_invertido_invertida)){
        cout << "Posições coincidem" << endl;
    }else{
        cout << "As posições não coincidem" << endl;
    }
    
    cout << "Produto dos dígitos: " << prod << endl;
    
    if(pos == prod){
        cout << "Produto e posição coincidem" << endl;
    }else{
        cout << "Produto e posição não coincidem" << endl;
    }
     
    cout << "Número em binário: " << bin << endl;
    
    if(ehPalindromo(bin,bin_invertido)){
        cout << "Binário é palíndromo" << endl;
    }else{
        cout << "Binário não é palíndromo" << endl;
    }
     
    if(ehSheldon(n,invertido,pos_invertido,pos_invertido_invertida,pos,prod,bin,bin_invertido)){
        cout << "É Sheldon" << endl;
    }else{
        cout << "Não é Sheldon" << endl;
    }
    
    return 0;
}

bool ehPrimo(int n){
    int cont = 2;
    if(n == 0 || n == 1){
        return false;
    }else{
        while(cont <= int(sqrt(n))){
            if(n % cont == 0){
                return false;
            }
            cont++;
        }
    }
    return true;
}

void posicao(int n,int& posicao){
    for(int e = 2;e <= n;e++){
        if(ehPrimo(e)){
            posicao++;
        }
    }
}
int digitos(int n){
    int x,digitos = 1;
    x=n;
    while(x >= 10){
        x = x/10;
        digitos++;
    }
    return digitos;    
}

int numero_invertido(int n,int& invertido){
        int num = n,digs = digitos(n);
        invertido=0;
        while(num >= 10){
        invertido += (num%10)*pow(10,digs);
        num = num/10;
        digs--;
       }
       invertido += (num%10)*10;
       invertido = invertido/10;
       return invertido;
}


bool posi_igual_reverso(int& pos_invertido,int& pos_invertido_invertida){
    if(numero_invertido(pos_invertido,pos_invertido_invertida) == pos){
        return true;
    }else{
        return false;
    }
}


void produto(int n,int& prod){
       int num=n;
       prod = 1;
       while(num >= 10){
        prod *= num % 10;
        num = num/10;
    }
    prod *= num % 10;
}

void binario(int n,int& bin){
    int a=0,x = n,p,b=0, vezes = 1;
    while (n!=1) {
        p=n % 2;
        b=(a*10)+p;
        n=n/2;
        a=b;
        if(p == 0){
        vezes++;
        }
    }
    p=n%2;
    b=(a*10)+p;
    if(x % 4 == 0){
        b = b * pow(10,vezes-1);
    }
    numero_invertido(b,bin);
}

bool ehPalindromo(int& b,int& b_i){
    numero_invertido(b,b_i);
    if(b == b_i){
        return true;
    }else{
        return false;
}
}


bool ehSheldon(int n,int& invertido,int& pos_invertido,int& pos_invertido_invertida,int& pos,int& prod,int& bin,int& bin_invertido){
    if(ehPrimo(n) && ehPrimo(invertido) && posi_igual_reverso(pos_invertido,pos_invertido_invertida) && pos == prod && ehPalindromo(bin,bin_invertido)){
        return true;
    }else{
        return false;
    }
}
