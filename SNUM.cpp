/*
 Nguyen Dinh Toan 18CNTT04
 user008
 
 */


#include <iostream>
#include <string>
#include <math.h>

using namespace std;


string s = "";


int charToNum(char c){
    
    int charNum[10] = {48,49,50,51,52,53,54,55,56,57};
    
    for (int i=0; i<10; i++) {
        if(charNum[i] == c){
            return i;
        }
    }
    
    return 0;
}
int stringToNumber(string s){

    int sNum = 0;

  
    int muLuyThua = 0;
    
    for (int i = (int)( s.size() - 1); i >= 0; i--) {
        int num = charToNum(s[i]);
        

        
        sNum += num * (pow(10, muLuyThua));
        
        muLuyThua++;
    }
    return sNum;
    
}

int main(){


    
    cin >> s;
    int sum = 0;
    int output = 0;
    
    for (int i =0; i<s.size(); i++) {
        
        int num = charToNum(s[i]);
        
        sum += num;
        
    
        
    }
    
    int theNumber = stringToNumber(s);
    
    if(theNumber % sum == 0){
        output = 1;
    }
    
    cout << output;
    
    return 0;
}
