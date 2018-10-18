/*
 User008
 Nguyen Dinh Toan
 18CNTT04
 */


#include <iostream>

using namespace std;

int main() {
    int n = 1;
    int num;
    long long sum = 0;
    
    bool isSubpascen = true;
    

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        
        if(sum < num){
            isSubpascen = false;
        }
    
        sum += num;
        
       
    
    }
    
    if(isSubpascen){
        cout << "TRUE";
    }else{
        cout << "FALSE";
    }
    
   
    
    return 0;
}
