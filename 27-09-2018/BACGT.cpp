#include <iostream>

using namespace std;


int deg(long int n, int v){
    
    int d = 0;
    
    if(n == 0 || v == 0){
        return 0;
    }
    while(n != 0){
        
        n /= v;
        d += n;
        
        
    }
    
    return d;
}


int main(){
    
    int n;
    int d;
    
    cout << "In:";
    
    cin >> d;
    cin >> n;
    

    int degValue = deg(n, d);
    
    cout <<degValue;
    
    return 0;
}
