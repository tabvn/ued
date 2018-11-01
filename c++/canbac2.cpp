#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double canX(double n){
	if(n == 1){
		return sqrt(2);
	}
	return sqrt(2*n + canX(n-1));
}
int main(){
	int x;
	cin >> x;
	cout << fixed << setprecision(4) << canX(x);
	return 0;
}