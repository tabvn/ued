#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    int diem = 0;
    cin >> s;
    
    // S = 83 ASCII
    
    int d =0;
    char lastChar;
    
    for (int i =0; i < s.size(); i++) {
        lastChar = s[i];
        
        if(s[i] == 83){
            d++;
            
            diem += d;
            
        }else{
            d = 0;
            
        }
        
        
        
        
    }
    
    cout << diem;
    
    return 0;
}
