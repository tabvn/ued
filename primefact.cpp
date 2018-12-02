#include <iostream>
#include <vector>

using namespace std;

void primeFact(int n){

	for (int i = 2; i <=n; ++i){
		while(n%i == 0){
				cout << i << " ";
				n /= i;
		}
	}
}

int main(){


	int n;
	cin >> n;

	primeFact(n);


	return 0;
}