#include <iostream>

using namespace std;

long long arr[1000000];

int timB(long long n, int b ){
   
    long long value = n;
    
    
    long long inc = 0;
    
    while (value > 0) {
        long long soDu = value%b;
        value /= b;
        
        arr[inc] = soDu;
        inc++;
        
        //cout << "value:" << value << endl;
        
        
        if(value == 0){
            // bat dau kiem tra
            bool same = true;
            
            long long lastValue = arr[0];
            
            
            for (int i = 0; i< inc; i++) {
                if(lastValue != arr[i]){
                    same = false;
                }
            }
        
            if(!same){
                // tang b++
                b++;
                return timB(n, b);
            }
        }
        
    }
    

    return b;
}
int main(){
    
   //cout << "Test";
    
    long long n;
    
    
    cin >> n;
    
    int b = 2;
    
    b = timB(n,b);
    
    cout << b;
    
    return 0;
}

