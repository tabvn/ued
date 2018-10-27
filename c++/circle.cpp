#include <iostream> 
using namespace std;

int howManyCircleInside(int n){
	
	int l = n*2;
	int minus = 4;
	if(n %2 == 0) {
		minus = 12;
	}
	return l*l - (2*l + 2*(l-2)) - minus;
}

int main(){
	
	int n, t;

	/*
	l = n*2;
	Tong so hinh tron nam trong = l*l - ((2*n) + 2*(n-2))
	*/
	cin >> t;

	for (int i = 0; i < t; ++i){
		cin >> n;
		cout << howManyCircleInside(n);
	}


	return 0;
}