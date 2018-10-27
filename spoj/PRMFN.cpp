#include <iostream> 
#include <math.h>
using namespace std;

bool isPrime(long long n){

	if(n < 2){
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i){
		if(n %i == 0){
			return false;
		}
	}
	return true;
}

bool isPrimeDigits(long long n){

	long long digit;

	while(n>0){

		digit = n%10;
		if(!isPrime(digit)){
			return false;
		}
		n /= 10;
	}

	return true;
}

long long findNumOfPrime(long long n){
	long long total = 0;

	for (int i = 0; i <= n; ++i){
		if(isPrimeDigits(i) && isPrime(i)){
			total ++;
		}
	}

	

	return total;
}

int main(){
	

	int t;
	long long n;
	cin >> t;
	long long v[t];

	for (int i = 0; i < t; ++i){
		cin >> n;
		v[i] = n;

	}

	for (int i = 0; i < t; ++i){
		cout << "Case "<< (i+1) << ": " << findNumOfPrime(v[i]) << endl;
	}
	return 0;
}