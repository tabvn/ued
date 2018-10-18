#include <iostream>


using namespace std;

long long gt(long int n){
	long long value = 1;
	if(n == 0){
		return 1;
	}
	for (int i = 1; i <= n; ++i){
		value *= i;
	}

	return value;
}

int main(){
	long int n;
    cin >> n;
    cout << n << "! = " << gt(n);
	return 0;
}