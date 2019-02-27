#include <iostream> 
#include <math.h>

using namespace std;
/*
n = 1 || n=2 => 1
*/
int fn(int n){
	if(n == 1 || n==2){
		return 1;
	}
	return fn(n-1) + fn(n-2);
}

/*
Binet's Fibonacci Number Formula
*/

int alterFn(int n){
	return (pow(1+sqrt(5),n) - pow(1-sqrt(5),n))/(pow(2,n)*sqrt(5));
}
int main(){
	int n;
	cin >> n;
	cout << alterFn(n);
	cout << endl;
	cout << fn(n);
	return 0;
}