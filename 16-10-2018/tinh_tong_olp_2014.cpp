#include <iostream>
#include <math.h>

using namespace std;

/*
1^2 + 2^2 + n^2 = [n*(n+1)*(2*n +1)]/6
*/

long long sum(long long n){

	return (n*(n+1)*(2*n +1))/6;
}
int main(){

	long long a,b,s;
	float x,y;

	cin >> x >> y;
	
	a = floor(x);
	b = floor(y);

	if(a == x){
		a++;
	}
	if(b == y){
		b--;
	}

	s = sum(b) - sum(a -1);
	cout << s%1000000007; 

	return 0;
}