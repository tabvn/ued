#include <iostream>

using namespace std;

/*
 Return false vi tri da ton tai
 Retur true: chua ton tai, vi tri con trong => OK
 
 */
bool kiemtra(int *arr, int num, int max){
    if(max == 0){
        return true;
    }
    for (int i = 0; i <max; ++i){
        //cout << "Kiemtra: " << num << " " << arr[i] << " index:" << i  << endl;
        if(arr[i] == num){
            return false;
        }
    }
    
    return true;
}

int timM(int* ids, int n, int m){
    
    int arrIndex[n];
    int increase = 0;
    for (int i = 0; i < n; ++i){
        int indexNum = ids[i] % m; // chia lay du
        
        if(kiemtra(arrIndex, indexNum, increase)){
            if(i == (n -1)){
                return m;
            }
            arrIndex[increase] = indexNum;
            increase++;
        }else{
            // khong thoa man m, tang m them 1
            m++;
            timM(ids, n, m);
        }
    }
    
    return m;
    
}
int main(){
    

    int n,m;
    
    cin >> n;
    
    int num;
    int ids[n];
    
    for (int i = 0; i < n; i++){
        cin >> num;
        ids[i] = num;
    }
    
    
    if(n == 1){
        cout << 1;
    }else{
        m = 2;
        int foundNum = timM(ids, n, m);
        cout << foundNum;
    }
    
    
    
}
