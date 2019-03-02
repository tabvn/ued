/**
tinh A(m,n)
*/
#include <iostream>
using namespace std;

long long ackermann(int m, int n){

	if(m == 0){
		return n+1;
	}

	if(n == 0){
		return ackermann(m-1, 1);
	}

	return ackermann(m-1, ackermann(m, n-1));
}
int main(){
	
	int m,n;

	cout << "Nhap m: ";

	cin >> m;

	cout << "Nhap n: ";
	cin >> n;

	cout << "A(" << m << "," << n << ") = " << ackermann(m,n);
	return 0;
}