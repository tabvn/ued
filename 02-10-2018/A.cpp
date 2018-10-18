#include <iostream>
using namespace std;

/*
 để 3 cạnh là 1 tam giác thì:
 + Tổng 2 cạnh phải lớn hơn canh còn lại
 + Tam giac vuông cân thì sẽ có chu vi lơn nhất
 */

bool laTamGiac(long int a, long int b, long int c){
    
    if(a ==0 || b == 0 || c== 0){
        return false;
    }
    return (a +b > c && a+c > b && b+c > a);
    
}


int main(){
    
    
    int lines;
    long int num;
    
    cin >> lines;
    long int arr[lines];
    
    
    
   long int S = 0;
    for (int i =0; i < lines; i++) {
        cin >> num;
        arr[i] = num;
    }
    
    long int inc = 0;
    
    for (int a = 0 ; a < lines; a++) {
        
        int bb = a+1;
        
        for (int b = bb; b < lines; b++) {
            
            int cc = b+1;
            
            for (int c = cc; c < lines; c++) {
                
                // kiem tra xem cach cap a, b, c nay có phải là tam giac không
                
                if(laTamGiac(arr[a], arr[b], arr[c])){
                    
                    // neu la tam giac ta kiem tra chu vi
                    
                    long int chuVi = arr[a] + arr[b] + arr[c];
                    
                    if( chuVi > S){
                        S = chuVi;
                    }
                    
                    
                    inc++; // tăng biến đếm số tam giác
                    
                }
                
                
            }
        }
        
        
    }
    
    // giờ kiểm tra xem inc > 0 thì tồn tại tam giác, còn inc = 0; thi chứng tỏ không có tam giác nào
    if(inc == 0 || S == 0){
        cout << 0;
    }
    cout << S;
    
    return 0;
}
