#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("BOT.INP");
ofstream fo ("BOT.OUT");

vector<long int> a;

void calculate() 
{ 
	int _size = a.size();
    int start =0;
    int end = 0;
   	int s = 0; 
  
  	long long maxValue = a[0]; 
    long long maxEnd = 0;
    for (int i=0; i< _size; i++ ) 
    { 
        maxEnd += a[i]; 
        if (maxValue < maxEnd) 
        { 
            maxValue = maxEnd; 
            start = s; 
            end = i; 
        } 
        // ket qua am thi reset lai tong va vi tri bat dau
        if (maxEnd < 0) 
        { 
            maxEnd = 0; 
            s = i + 1; 
        } 
    } 
    
    fo << (start+1) << " " << (end +1) << " " << maxValue; 

    
} 

int main(){
	
	int n;
	long int ai;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> ai;
		a.push_back(ai);
	}

	calculate();

	fi.close();
	fo.close();

	return 0;

}