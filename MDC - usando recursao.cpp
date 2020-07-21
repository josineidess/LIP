#include <iostream>

using namespace std;

int mdc(int x,int y);

int main() {
    int x,y;
    cin >> x;
    cin >> y;
    cout << "MDC(" << x << " , " << y << ") = " <<mdc(x,y) << endl;
    return 0;
}

int mdc(int x,int y){
    if(y == 0){
        return x;
    }else{
        x = x % y;
        return mdc(y,x);
    }
}
