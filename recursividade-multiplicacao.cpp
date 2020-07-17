#include <iostream>

using namespace std;

int mult(int x,int y);

int main(){
    int x,y;
    cin >> x;
    cin >> y;
    cout << x << " * " << y << " = " << mult(x,y) << endl;
    return 0;
}

int mult(int x,int y){
    if(y == 0){
        return y;
    }else{
        return x + mult(x,y-1);
    }
}
