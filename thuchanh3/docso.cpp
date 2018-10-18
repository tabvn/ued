#include <iostream>
#include <string>

using namespace std;


string docHangChuc(int n){
    string s;
    
    switch (n) {
        case 0:
            s = "khong";
            
            break;
        case 1:
            
            s = "mot";
            
            break;
            
        case 2:
            s = "hai";
            
            break;
            
        case 3:
            
            s = "ba";
            
            break;
            
        case 4:
            
            s = "bon";
            
            break;
            
        case 5:
            s = "nam";
            
            break;
            
            
        case 6:
            
            s = "sau";
            
            
            break;
            
        case 7:
            
            s = "bay";
            
            break;
        case 8:
            
            s = "tam";
            
            break;
            
        case 9:
            
            s = "chin";
            
            break;
            
        case 10:
            
            s = "muoi";
            
            
            break;
        default:
            break;
    }
    
    return s;
}

string docHangDonVi(int n){
    string s;
    
    switch (n) {
            
        case 1:
            
            s = "mot";
            
            break;
            
        case 2:
            s = "hai";
            
            break;
            
        case 3:
            
            s = "ba";
            
            break;
            
        case 4:
            
            s = "bon";
            
            break;
            
        case 5:
            s = "lam";
            
            break;
            
            
        case 6:
            
            s = "sau";
            
            
            break;
            
        case 7:
            
            s = "bay";
            
            break;
        case 8:
            
            s = "tam";
            
            break;
            
        case 9:
            
            s = "chin";
            
            break;
            
        default:
            break;
    }
    
    return s;
}

string doc(int num, int hc, int hdv){
    
    
    
    string s = "";
    if(num == 10){
        s = "muoi";
    }
    else if(num < 10){
        s = docHangChuc(num);
        
    }
    else if(num > 10 && num < 20){
        s+= "muoi";
        if(hdv > 0){
            s+= " ";
            s+= docHangDonVi(hdv);
        }
    }
    else if (num >= 20 && num <=99){
        
        s+= docHangChuc(hc);
        s+= " muoi";
        if(hdv > 0){
            s+= " ";
            s+= docHangDonVi(hdv);
        }
    }
    else{
        s = "chua biet doc";
    }
    return s;
}

int main(){
    
    
    int num, hdv, hc;
    
    cin >> num;
    
    hdv = num % 10;
    hc = (num/10) % 10;
    
    cout << doc(num, hc, hdv) << endl;
    return 0;
}
