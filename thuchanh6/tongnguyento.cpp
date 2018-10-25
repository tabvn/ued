#include <iostream>
#include <math.h>

using namespace std;




bool isPrime(long int n){
	if(n < 2){
		return false;
	}

	for(int i =2 ; i<= sqrt(n); i++){
		if(n % i == 0){
			return false;
		}
	}

	return true;

}

long long primeSum(long int n){

	long long sum = 0;

	for (int i = 0; i < n; ++i){
			if(isPrime(i)){
				sum += i;
			}
	}
	return sum;
}

int main(){

	long int n;
	cin >> n;
	cout << primeSum(n);
	return 0;
}