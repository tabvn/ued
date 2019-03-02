/*
Fibonacci
*/
#include <iostream>
using namespace std;

long long fib(int n){
	if(n <= 2){
		return 1;
	}
	return fib(n-1) + fib(n-2);

}


int main(){
	
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Ket qua Fib(" << n << ") = " << fib(n); 
	return 0;
}