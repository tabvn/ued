#include<iostream>
#include <vector>
using namespace std; 

vector<long int> v;

long long findMiniumRange(){

    int i = 0;
    int j = v.size() -1;

    long long left = 0;
    long long right = 0;
    long long minValue = 9223372036854775807;
    long long value;
    
    for (int i = 0; i < v.size(); ++i){
        left += v[i];
    }


    for (int i = v.size() -1; i >= 0; --i){
        left -= v[i];
        right += v[i];

        if(left > right){
             value = left - right;
         }else{
             value = right - left;
         }
        if(value < minValue){
            minValue = value;
        }
    }
    
    return minValue;
}
int main() 
{ 
    
    int n;
    long int a;
    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> a;
        v.push_back(a);
    }

    cout << findMiniumRange();
    return 0; 
} 
