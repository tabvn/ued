#include <iostream>
using namespace std;

/*
* S = 1+2 +3+......+n
*/

long long sum(int n){

	long long s = 0;

	for (int i = 1; i <= n; ++i){
		s+= i;
	}

	return s;
}

long long recursiveSum(int n){

	if(n == 1){
		return 1;
	}

	return n + recursiveSum(n-1);

}

int main(){
	
	int n;

	cout << "Nhap N: ";

	cin >> n;

	cout << "ket qua khong dung de quy: " << sum(n) << endl;
	cout << "ket qua dung de quy: " << recursiveSum(n);

	return 0;
}