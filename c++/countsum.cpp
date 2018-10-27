#include <iostream> 
using namespace std;

void countsum(long long n){

	int numLen = 0;
	int sum = 0;
	while(n > 0){
		sum+= n%10;
		n /=10;
		numLen++;
	}

	cout << numLen << " " << sum;
}
int main(){
	
	long long n;
	cin >> n;

	countsum(n);

	return 0;
}