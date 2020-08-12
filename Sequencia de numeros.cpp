#include <iostream>

using namespace std;

int n;
bool aceita = true;
int menor;
int cont=0;
int main() {
    while(aceita){
        cin>>n;
        if(cont==0){
            menor=n;
        }else{
            if(n<menor && n!=0){
                menor=n;
            }
        }
        if(n==0){
            aceita=false;
        }else{
            cont++;
        }
    }
    cout<<menor<<endl;
    return 0;
}
