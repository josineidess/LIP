#include <iostream>
#include <iomanip>

using namespace std;

int quant,n;
float media,soma=0;

int main(){
    cin>>quant;
    for(int e=0;e<quant;e++){
        cin>>n;
        soma+=n;
    }
    media=soma/quant;
    cout<<fixed<<setprecision(2);
    cout<<media<<endl;
    return 0;
}
