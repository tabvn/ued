#include <iostream> 
using namespace std;


int main(){
	int n1, n2;

	cin >> n1;
	cin >> n2;

	long long sum = 0;
	for (int i = n1; i <=n2; ++i){
		if(i % 2 == 0){
			// day la so chan
			sum += i;
		}
	}

	cout << sum;

	return 0;
}