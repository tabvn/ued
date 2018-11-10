#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long a,b;


bool isPrime(long long n){
	if(n < 2){
		return false;
	}
	bool snt = true;

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0){
			snt = false;
		}
	}
	return snt;

}



bool doiXung(long long n){
	long long reverse = 0;
	long long number = n;
	while(number > 0){
		reverse = reverse*10 + number%10;
		number /= 10;
	}

	return reverse == n;
}

int main(){
	int t;

	cin >> t;

	for (int k = 0; k < t; ++k){
		cin >> a >> b;
		long long increase = 0;
		for (int i = a; i <=b; ++i){
			if(isPrime(i) && doiXung(i)){
				increase++;
			}
		}
		cout << increase << endl;
	}
	


	return 0;
}