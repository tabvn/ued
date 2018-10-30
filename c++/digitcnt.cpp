#include <iostream> 
using namespace std;


int main(){
	long int n;
	int test,digit;

	cin >> test;

	for (int i = 0; i < test; ++i){
		cin >> n;	
		long int value = n;
		int total = 0;
		while(n>0){
			digit = n%10;
			if(digit != 0 && value%digit == 0){
				total++;
			}
			n /=10;
		}

		cout << total;
	}
	

	return 0;
}