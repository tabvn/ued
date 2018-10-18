#include <iostream>

using namespace std;

int main(){


    
    int num,min, max;
    
    min =0;
    max =0;
    
    for (int i=0; i<4; i++) {
        cin >> num;
        if(i == 0){
            min = num;
        }
        if(num < min){
            min = num;
        }
        if(num > max){
            max = num;
        }
        
    }
    
    cout << max << " " << min;
    
    
    return 0;
}
