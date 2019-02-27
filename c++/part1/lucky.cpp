#include <iostream> 
using namespace std;


bool isLuckyNumber(int n){

	int digit;
	while(n > 0){
		digit = n%10;
		if(digit != 4 && digit != 7){
			return false;
		}
		n /= 10;
	}

	return true;
}
int main(){
	
	int k;
	
	cin >> k;
	int inc = 0;
	int num = 1;
	while(inc <= k){
		if(isLuckyNumber(num)){
			inc++;
		}
		if(inc == k){
			break;
		}
		num++;
	} 
	cout << num;

	return 0;
}