#include <iostream>

using namespace std;

int main(){
    int n;
    int num;
    long long S =0;
    //Input
    cin >> n;
    int arr[n];
    
    for (int i = 0; i<n; i++) {
        cin >> num;
        arr[i] = num;
        
    }
    int Bi;
    for (int i=0; i<=n; i++) {
        Bi = arr[i];
        for (int j=i+1; j < n; j++) {
            S+= Bi*arr[j];
        }
        
    }

    cout << S;
    
    return 0;
}
