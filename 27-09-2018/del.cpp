#include <iostream>

using namespace std;

int giaiThua(int num){
    
    if(num == 0){
        return 1;
    }
    
    int value = 1;
    for (int i = 1; i <=num; i++) {
        value  = value * i;
        
    }
    
    return value;
}

int chinhHop(int n, int k){
    
    return (giaiThua(n)/(giaiThua(k) * (n - k)));
}

int main(){
  
    
    int n;
    

    
    cin >> n;

    
    int num;
    
    bool tatCaLaSoChan = true;

    int soChan = 0;
    int soLe = 0;
    
    
    for (int i = 1; i <= n; i++) {
        if(i % 2 != 0){
            tatCaLaSoChan = false;
            
            soLe ++;
        }else{
            soChan ++;
        }
    }
    

    
    if(tatCaLaSoChan){
        cout << chinhHop(n, 2);
    }else{
        
        if(soChan == 0){
            // tat ca la so le
            if(n % 2 != 0){
                // n la so le
                cout << 0;
            }else{
                
                // n la so chan
                cout << chinhHop(n, 2);
            }
        }else{
            
            // gom ca so le va so chan
            int t;
            
            if(soLe %2 == 0){
                // so luong le la chan
                t = chinhHop(soChan, 2) * chinhHop(soLe, 2);
                cout << t;
            }else{
                t = soLe * soChan;
                
                cout << t;
            }
        }
        
    }
    
    
    return 0;
}
