#include <iostream>
#include <math.h>

using namespace std;


long int daoSo(long int n){

	long int sum = 0;
	if(n < 10){
		return n;
	}
	while(n > 0){
		sum = sum*10+(n%10);
		n/=10;
	}

	return sum;
}


int main(){

	long int n;
	cin >> n;
	long int value = daoSo(n);
	cout << "So dao: ";
	cout << value;
	cout << " ";
	cout << value * 2;

	return 0;

}