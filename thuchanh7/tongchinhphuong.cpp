#include <iostream> 
#include <math.h>
using namespace std;


bool isCp(long int n){
	double a = sqrt(n);

	if((int) a = a){
		return true;
	}

	return false;
}

int main(){
	
	long int n,x;
	long long sum;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> x;
		if(isCp(x)){
			sum+= x;
		}
	}

	cout << sum;
	return 0;
}