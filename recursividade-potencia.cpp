#include <iostream>

using namespace std;

int pot(int b,int e);

int main() {
    int b,e;
    cin >>b;
    cin >> e;
    cout << "pow( " << b << " , " << e << " ) = "<<pot(b,e) << endl;
    return 0;
}

int pot(int b,int e){
    if(e == 0 || b == 0){
        if(b ==0){
            return 0;
        }else{
          return 1;
        }
    }else{
        return b * pot(b,e-1); 
    }
}
