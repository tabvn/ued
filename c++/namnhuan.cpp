/*
 Nguyen Dinh Toan 18CNTT04
 MSV: 3120218201
 */

#include <iostream>

using namespace std;

int main(){
    unsigned int n;
    bool nhuan = false;
    
    cin >> n;
    
    if(n % 400 == 0 || (n%4 == 0 && n %100 != 0)){
        nhuan = true;
    }
    
    if(nhuan){
        cout << "nhuan";
    }else{
        cout << "khong nhuan";
    }
    
}
