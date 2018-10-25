#include <iostream>
using namespace std;

long long n;
long int m;

long long ct(){

	long long value = 0;
	for (int i = 1; i <=n; ++i){
		value += (i%m * i%m)%m;
	}
	return value % m;
}


int main(){

	
	cin >> n >> m;
	cout << ct();

	return 0;
}