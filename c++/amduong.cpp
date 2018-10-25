#include <iostream> 
using namespace std;

int main(){
	long int n;

	cin >> n;
	long int value = n;
	bool notFound = true;
	for (int i = 2; i < n; ++i){
		while(value % i == 0){
			notFound = false;
			cout << i;
			value /= i;
		}
	}

	if(notFound){
		cout << -1;
	}

	return 0;
}