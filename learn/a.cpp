#include <iostream>
#include <math.h>

using namespace std;

struct Point{
    int x;
    int y;
    
};

Point A,B,C;

// tinh do dai 2 diem

float length(Point a, Point b){
    
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}
int main(){
    
    
    int x, y;
    cin >> x >> y;
    A = Point{x,y};
    cin >> x >> y;
    B = Point{x, y};
    cin >> x >> y;
    C = Point{x,y};
    
    

    float AB = length(A, B);
    float BC = length(B, C);
    float AC = length(A, C);
    
    
    if(AC == (AB+BC)){
        // C nam ngoai AB
        cout << "TOWARDS";
    }
    else if(AC == (AB - BC)){
        // C nam giua A-B
        cout << "TOWARDS";
    }
    else if(BC == (AC + AB)){
        cout << "TOWARDS";
    }
    else{
        
        if(C.x > B.x && C.x > 0){
            // re phai
            cout << "RIGHT";
        }else{
            cout << "LEFT";
            
        }
    }
    
    return 0;
}


/*
-1 -1
-3 -3
-4 -4
 
-4 -6
-3 -7
-2 -6
 
 */
