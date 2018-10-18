
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

float gocTaoBoiKimGio(float gio){
    
    float deg = 360 - (float)(30 * gio);
    

    return deg;
}

float gocTaoBoiKimPhut(int phut){
    
    
    float d = (360/60) * phut;
    
    return d;
    
}


int main(){
  
    
    float gio, phut;
    scanf("%f:%f", &gio, &phut);
    
    float h = gio + (float)phut/60;
    
    float goc = 360 - (gocTaoBoiKimGio(h) + gocTaoBoiKimPhut(phut));
    
    // vi đề bài cho phép góc giữa 2 kim là nhỏ hơn 180 nên ta kiêm tra lan cuoi
    
    if(goc > 180){
        goc = 360 - goc;
    }
    
    cout << fixed << setprecision(3) << goc;
    
    

    return 0;
}