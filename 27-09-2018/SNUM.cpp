#include <iostream>

using namespace std;

int sumNumber(long long num){
    
    int t = 0;
    
    long long value = num;
    while (value > 0) {
        int n = value % 10;
        value /= 10;
        
        t += n;
    }
    
    return t;
}

int main(){
    
    long long n;

    cin >> n;
    
    int sum = sumNumber(n);
    
    if(n % sum == 0){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
