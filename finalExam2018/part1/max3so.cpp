#include <iostream>
using namespace std;

int main(){

	long long a,b,c;

	cin >> a >> b >> c;
	long long max = a;
	
	if(b > max){
		max = b;
	}
	if(c > max){
		max = c;
	}

	cout << max;

	return 0;
}