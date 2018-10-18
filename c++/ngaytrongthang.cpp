/*
 Nguyen Dinh Toan 18CNTT04
 MSV: 3120218201
 */

#include <iostream>

using namespace std;

/*
 return 1 la nam nhuan

 */
int check_year(int n){
    
    if(n % 400 == 0 || (n%4 == 0 && n %100 != 0)){
        return 1;
    }
    
    return 0;
    
}

int getNumDaysOfMonth(int month, int year){
    
    int numDays = 30;
    
    switch ( month) {
        case 2:
            
            if(check_year(year)){
                numDays = 29;
            }else{
                numDays = 28;
            }
            
            break;
           
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            numDays = 31;
            
            break;
            
        default:
            
            numDays = 30;
            
            break;
    }
    
    return numDays;
}

int main(){
    int month, year;
    
    /* nam nhuan thang 2 se co 29 ngay
    nam khong nhuan thang 2 se co 28 ngay */

    cin >> month;
    cin >> year;
    
    int numDays = getNumDaysOfMonth(month, year);
    
    cout <<  numDays << " ngay";
    return 0;
}
