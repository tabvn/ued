/*
 User008
 Nguyen Dinh Toan
 18CNTT04
 */


#include <iostream>

using namespace std;

bool isExistInList(int arr[], int num,  int max){
    
    for (int i = 0; i < max; i++) {
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

int main() {
    
    
    
    int n, num;
    
    cin >> n;
    int arr[n];

    int total = 0;
    
    
    // input
    int inc = 0;
    
    for (int i = 0; i < n; i++) {
        
        cin >> num;
        if(!isExistInList(arr, num, inc)){
            arr[i] = num;
            total ++;
        }
        
        inc ++;
    }
    

    cout << total;

    
    return 0;
}
