#include <iostream>
#include <math.h>

using namespace std;

bool snt(long long a){
	if(a < 2){
		return false;
	}

	for (long long i = 2; i <= sqrt(a); ++i){
		if(a %i == 0){
			return false;
		}
	}

	return true;

}
int main(){

	int n;
	long long a;

	cin >> n;

	long long s = 0;

	for (int i = 0; i < n; ++i){
		
		cin >> a;

		if(snt(a)){
			s+= a;
		}
	}

	cout << s;

	return 0;
}