#include <iostream>
using namespace std;


int solve(long long a[], int n){

	if(n < 3){
		return -1;
	}

	long long c[2];

	c[0] = a[0];
	c[1] = a[1];

	int max = -1;
	int maxSofar = -1;
	for (int i = 2; i < n; ++i){
			if(a[i] == c[0] + c[1]){
				if(maxSofar == -1){
					maxSofar = 2;
				}
				maxSofar ++;
			}else{
				if(maxSofar > max){
					max = maxSofar;
					
				}
				maxSofar = -1;
			}

			c[0] = c[1];
			c[1] = a[i];
	}

	if(maxSofar > max){
		max = maxSofar;
	}

	return max;

}
int main(){


	int n;

	cin >> n;

	long long a[n];

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	cout << solve(a, n);


	return 0;
}