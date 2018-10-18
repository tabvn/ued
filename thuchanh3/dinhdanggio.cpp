#include <iostream>
using namespace std;

void hienThi(int h, int m){
    int gio = h;
    bool am = true;

    if(h == 12){
        am = false;
    }
    if(h > 12){
        am = false;
        gio = h - 12;
    }
    if(h >= 24){
        am = true;
        gio = h - 24;
    }
    if(gio < 10){
        cout << "0"<<gio;
    }
    else{
        cout << gio;
    }
    cout << ":";
    // hien thi phut
    if(m < 10){
        cout << "0"<< m;
    }else{
        cout << m;
    }
    cout << " ";
    // am/pm
    if(am == true){
        cout << "am";
    }else{
        cout << "pm";
    }
    
    
}
int main(){
    int h, m;
    char s;
    cin >> h >>s >> m;
    hienThi(h, m);
    return 0;
}
