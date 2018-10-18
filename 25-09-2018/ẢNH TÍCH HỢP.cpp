/*
 User008
 Nguyen Dinh Toan
 18CNTT04
 */


#include <iostream>

using namespace std;

int main() {
    
    
    
    int m, n, num;
    
    cin >> m;
    cin >> n;
    
    int sum = 0;
    int arr[m*n];
    
    
    
    for (int i = 0; i < m*n; i++) {
        cin >> num;
        
        arr[i] = num;
    }
    
    int increase = 1;
    
    for (int i = 0; i < m*n; i++) {
        

        int outputNumber = arr[i] +sum;
    
        cout << outputNumber << " ";
        
        if(increase % 3 == 0){
            cout << endl;
        }
        cout << endl;
        
        sum += arr[i];
        
        increase ++;
        
    }
    return 0;
}
