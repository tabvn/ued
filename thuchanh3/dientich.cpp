#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main(){

    /*
     goc  = PI * theta/180
     s = a*b* sin(goc) /2 ;
     */

    
    int a;
    int b;
    int theta;
    float s;
    
    cin >> a >> b >> theta;
    
    float goc = 3.14*theta/180;
    s = (a * b * sin(goc))/2;
    
    cout << "Dien tich: " <<fixed<< setprecision(2)<<s;
    return 0;
}
