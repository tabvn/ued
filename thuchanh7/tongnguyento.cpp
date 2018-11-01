#include <iostream> 
#include <math.h>

using namespace std;

bool isPrime(long int n){
	if(n < 2){
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i){
		if(n%i == 0){
			return false;
		}
	}

	return true;
}

int main(){
	
	long int n,a;
	long long sum;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		if(isPrime(a)){
			sum+= a;
		}

	}
	cout << sum;
	return 0;
}