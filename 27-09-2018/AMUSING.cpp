#include <iostream>

using namespace std;


long int MAX = 10000000000; // 10^9

void displayArr(long int arr[], long int max){
    

    cout << "Array:";
    
    for (int i = 0; i < max; i++) {
        
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int getFirstCharacterOfNumber(long int n){
    
    
    if(n == 0){
        return 0;
    }
    int tempArr[10]; // vi < 1 ty
    
    int inc = 0;
    
    while (n > 0 ) {
        
        int c = n % 10;
    
        n /= 10;
        
        tempArr[inc] = c;
        inc ++;
    }
    



    
    
    int lastIndex = inc == 0 ? 0:  (inc -1);
    
    return tempArr[lastIndex]; // lay so cuoi cung của mảng cũng là số đầu tiên của chữ số
    
}

void numToArrayList(long int *arr, long int n){
    
    


    for (int i = 0; i <n; i++) {
        
        int num = i +1;
        arr[i] = num;
    }
    // sap xep mảng theo dãy số vui vẻ :D tăng dần
    
    
    long int tempNum;
    
    for (int i = 0; i < n; i++) {
        
        
        for (int j = 0; j <n; j++) {
            
           int ii = getFirstCharacterOfNumber(arr[i]);
           int jj = getFirstCharacterOfNumber(arr[j]);
            
            if( jj > ii ){
                
                // doi vi tri cho nhau
               
                
               tempNum = arr[i];
               arr[i] = arr[j];
               arr[j] = tempNum;
                
            }
        }
    }
    
    //displayArr(arr, n); // dùng để test xem mảng sắp xep theo số vui vẻ chưa
    

}

long int timKiem(long int *arr, long int n, long int k, long int m){
    
    // n < 10^9
    
    // kiem tra neu n >= 10^9 theo gioi han bai toan, thi tra ve false;
    
    if(n >= 1000000000){
        return 0;
    }
    
    long int foundNumber = 0;
    
    for (int i = 0; i< m; i++) {
        
        if(arr[i] == k && i == (m - 1)){
            
            foundNumber = n;
            break;
        }
    }
    
    if(foundNumber > 0){
        return foundNumber;
    }else{
        // neu khong tim thay thi tang n len 1,
        n++;
        
        numToArrayList(arr, n);
        return timKiem(arr, n, k, m);
    }
    
    return false;
    
}


int main(){
    
    
    long int *arr = new long int(MAX);
    
    long int m, k;
    int soLanTest;
    
    long int n;
    
    cin >> soLanTest;
    cin >> m; // vi tri
    cin >> k; // so k can tim tai vi tri m
    
    
    for (int i=0; i < soLanTest; i++) {
        n = 0; // giả sử n = 0;
        numToArrayList(arr, n);
        long int soVuiVe = timKiem(arr , n, k, m);
        
        cout << soVuiVe << endl;
    }
    
   
    
    
    
}