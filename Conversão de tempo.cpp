#include <iostream>

using namespace std;

int segundos;
int dias; //86400s
int horas; //3600s
int minutos; //60s

int main() {
    cin >> segundos;
    dias = segundos / 86400;
    segundos = segundos -(dias * 86400);
    horas = segundos / 3600;
    segundos = segundos - (horas * 3600);
    minutos = segundos / 60;
    segundos = segundos -(minutos * 60); 
    cout << dias <<" dias, " << horas << " horas, " << minutos << " minutos e " << segundos << " segundos"; 
    return 0;
}
