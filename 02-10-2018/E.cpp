#include <iostream>
//E
using namespace std;

int main(){
    float a,b;
    long long x, y;
    long long s = 0;
    
    cin >> a;
    cin >> b;
    
    x = (long long)a;
    y = (long long)b;
    
    /* tinh tong  cac so tu a -> b (a < b);
     s = ((a + b) * so phan tu) /2
     */
    
    if((float)x < a){
        x++;
    }
    
    if(x > y){
        cout << 0;
    }else{
        long long numCount = ((y - x) +1);
        s = ((x + y) * (numCount))/2;
    
        cout << s;
    }
    
    
    
    return 0;
}
