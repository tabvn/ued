#include <iostream>

using namespace std;


int main(){

    int h,m,s;
    
    /*
     0 <= h <= 23
     0 <= s <= 59
     */
    
    cin >> h >> m >> s;
    
    // sau khi nhập vào tăng thêm 1 giây
    s++;
    
    // kiểm tra second
    if(s == 60){
        m ++;
        s = 0;
    }
    if(m == 60){
        h++;
        m = 0;
        
    }
    if(h == 24){
        h =0;
    }
    
    cout << h << " " << m << " " << s;
    
    
    return 0;
}
