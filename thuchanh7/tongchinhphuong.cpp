#include <iostream> 
#include <math.h>
using namespace std;


bool isCp(long int n){
	double a = sqrt(n);

	long int b = a;

	if(b == a){
		return true;
	}

	return false;
}

int main(){
	
	long int n,x;
	long long sum = 0;
	cin >> n;
	for (long int i = 0; i < n; ++i){
		cin >> x;
		if(isCp(x)){
			sum+= x;
		}
	}

	cout << sum;
	return 0;
}