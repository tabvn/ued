#include <iostream>
#include <math.h>

using namespace std;

unsigned int n;

bool isPrime(){
	if(n < 2){
		return false;
	}
	bool prime = true;

	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			prime = false;
			break;
		}
	}

	return prime;
}



int main(){
	
	cin >> n;
	bool isPrimeNumber = isPrime();
	if(isPrimeNumber){
		cout << "nguyen to";
	}else{
		cout << "khong nguyen to";
	}

	return 0;
}