
#include <iostream>

using namespace std;

int main(){
    
   // cout << "Debug:";
    
    int n,k,m;
    
    cin >> n >> k >> m;
    
    int arr[n];
    
    int inc = 1;
    
    for (int i = 0; i < n; i++) {
        arr[i] = inc;
        inc++;
    }
    
    
    int index = 0;
    int tang = index;
    int vitri = 0;
    int matrix[k];
    
    while (true) {
        
        matrix[0] = arr[index];
        if(k == 1){
            index++;
            
        }else{
            
            for (int i=1; i<k; i++) {
                int theIndex = tang+i;
                if(theIndex > n-1){
                    
                    break;
                }
                if(i == k-1){
                    
                    matrix[i] = arr[theIndex];
                    //cout << " " << arr[theIndex];
                }else{
                    
                    matrix[i] = arr[index+i];
                    
                    // cout << " "<< arr[index+i];
                }
                
                if(i == k -1){
                    tang++;
                }
                
                if(theIndex == n-1){
                    // dat den vi tri cuoi
                    index++;
                    tang = index;
                }
                
                
            }
        }
        
        if(vitri == m){
            // tim thay va thoat ra vong lap
            break;
        }
        
        // cout << endl;
        vitri++;
        
    }
    
    
    for (int i = 0; i< k; i++) {
        if(i >0){
            cout << " ";
        }
        cout << matrix[i];
        
    }
    
    
    return 0;
}
