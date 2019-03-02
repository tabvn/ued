#include <iostream>
using namespace std;

long long solve(long long *arr, long long n){	

	long long m = arr[0];

	for (long long i = 0; i < n; ++i){
		if(arr[i] > m){
			m = arr[i];
		}
	}

	return m;
}

int main(){
	
	long long n;
	cin >> n;

	
	long long *arr = new long long[n];



	for (long long i = 0; i < n; ++i){
	
		cin >> arr[i];
	}

	cout << solve(arr, n);


	return 0;
}