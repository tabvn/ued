#include <iostream>
#include <math.h>


using namespace std;

long long ucln(long long a, long long b){

	if(a % b == 0){
		return b;
	}
	if(b % a == 0){
		return a;
	}

	while(a != b){

		if(a > b){
				b = b;
				a = a-b;
		}else{

			a = a;
			b = b -a;
		}
	}

	return a;
}
int main(){

	long long a,b;
	cin >> a >> b;
	cout << ucln(a,b);

	return 0;
}