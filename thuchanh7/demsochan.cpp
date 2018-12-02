#include <iostream> 
using namespace std;

int countEvenNumbers(long int n){

	int c =0;
	long int tmp;

	while(n > 0){
		tmp = n%10;
		if(tmp %2 == 0){
			c++;
		}
		n/=10;
	
	}

	return c;
}
int main(){
	long int n;
	cin >> n;

	cout << countEvenNumbers(n);
	return 0;
}