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


long int UCLN(long int a, long int b){

	if(a %b == 0){
		return b;
	}
	if(b%a == 0){
		return a;

	}
	
	while(a != b){
		if(a > b){
			a = a-b;
		}else{
			b = b-a;
		}
	}

	return a;

}
bool isThanThien(long int n){

	if(UCLN(n, daoSo(n)) == 1){
		return true;
	}

	return false;
}
int main(){

	long int n;
	cin >> n;
	
	if(isThanThien(n)){
		cout << "than thien";
	}else{
		cout << "khong than thien";
	}

	return 0;
}