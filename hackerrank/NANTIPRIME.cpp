#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const long long MAX = 1000000000;
// array to store prime factors
long long factor[MAX] = { 0 };

void khoiTao()
{
    factor[1] = 1;
    
   
    for (long long i = 2; i < MAX; i++)
        factor[i] = i;
    
    
    for (long long i = 4; i < MAX; i += 2)
        factor[i] = 2;
    
   
    for (long long i = 3; i * i < MAX; i++) {
        
  
        if (factor[i] == i) {
            
          
            for (long long j = i * i; j < MAX; j += i) {
                
                
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}

long int demSoUoc(long int n)
{
    if (n == 1)
        return 1;
    
    int ans = 1;
    
    
    long int dup = factor[n];
    
    
    int c = 1;
    
   
    long long j = n / factor[n];
    

    while (j != 1) {
        
        
        if (factor[j] == dup)
            c += 1;
        
        else {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }
        
        j = j / factor[j];
    }
    
    ans = ans * (c + 1);
    
    return ans;
}

long int smallest(long int num, int n)
{
    for (long int i = num+1;; i++)
        
        
        if (demSoUoc(i) > n)
            return i;
}


long long findNum(long int n){
    
    int soUoc = demSoUoc(n);
    
    return smallest(n, soUoc);
}

int main(){
    
    khoiTao();
    int t;
    long long x;
    
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> x;
        cout << findNum(x) << endl;
        //myArr.push_back(x);
    }
    

    return 0;
}
