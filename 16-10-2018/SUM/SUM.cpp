#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
//Users/toan/ued/16-10-2018/SUM

ifstream fi ("SUM.INP");
ofstream fo ("SUM.OUT");


long long sum(long long n){

	return (n*(n+1)*(2*n +1))/6;
}

int main(){

	long long a,b,s;
	float x,y;

	fi >> x >> y;
	
	a = floor(x);
	b = floor(y);
	if(a < x){
		a++;
	}
	

	s = sum(b) - sum(a -1);
	long long p = pow(10,9)+7;

	fo << (s%p);
	fi.close();
	fo.close();

}