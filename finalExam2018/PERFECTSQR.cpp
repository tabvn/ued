#include <iostream>
#include <math.h>

using namespace std;



bool scp(long long n){

  double x = sqrt(n);
	long long a = (long long) x;
	if(x == a){
		return true;
	}
	return false;
}
int main(){
	long long n;
	long long a;
	unsigned long long s = 0;

	cin >> n;

	for (long long i = 0; i < n; ++i){
		cin >> a;
		if(scp(a)){
			s += a;
		}
	}

	cout << s;

	return 0;
}