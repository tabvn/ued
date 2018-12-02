#include <iostream> 
#include <math.h>
using namespace std;

int main(){

	int n, negTotal, posTotal;
	double a;


	negTotal = 0;
	posTotal = 0;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a;
		if(a < 0){
			negTotal ++;
		}
		if(a > 0){
			posTotal ++;
		}
	}

	cout << negTotal << " " << posTotal;
	
	return 0;
}