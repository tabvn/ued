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

void find(long int m, long int n){
	for (int i = m; i <= n; ++i){
		if(isPrime(i)){
			cout << i << endl; 
		}
	}

}

int main(){

	int t;
	long int m,n;	
	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> m >> n;
		find(m,n);
		if(i < t-1){
			cout << endl;
		}
	}
	return 0;
}