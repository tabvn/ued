/*
 Nguyen Dinh Toan 18CNTT04
 MSV: 3120218201
 */

#include <iostream>

using namespace std;

int main(){
    
    int s, num;
    
    // Tong cac chu so tu n -> m: n = 0, m = num
    // s = (m+n)*((m-n)+1)/2
    
    cin >> num;
    
    s = (num+0) * (num - 0 + 1)/2;
    
    cout << s;

    
    return 0;
}
