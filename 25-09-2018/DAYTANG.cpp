/*
 User008
 Nguyen Dinh Toan
 18CNTT04
 */


#include <iostream>

using namespace std;

int main() {
    
    int n;
    int num;
    
    
    
    cin >> n;
    
    
    int count = 1;
    int lastNum = 0;
    int maxCount = 0;
    
    
    // input
    for (int i= 0; i < n; i++) {
        cin >> num;
        
        int currentNum = num;
        
        
        if(currentNum < lastNum){
            
            if(count > maxCount){
                maxCount = count;
            }
            // het day tang
            count = 1;
            
        }else{
            count ++;
        }
        
        lastNum = currentNum;
        
        
        
    }
    
    
    
   
    
    cout << maxCount;
    
    return 0;
}
