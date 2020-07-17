
#include <iostream>

using namespace std;

bool ehPar(int n);

int main()
{
    int n;
    cin >> n;
    cout << n << " é ";
    if(ehPar(n)){
        cout << "par" << endl;
    }else{
       cout << "ímpar"<< endl; 
    } 
    return 0;
}

bool ehPar(int n){
    if(n == 1 || n == 0){
        if(n == 1){
            return false;
        }else{
            return true;
        }
    }else{
        return ehPar(n-2);
    }
}
