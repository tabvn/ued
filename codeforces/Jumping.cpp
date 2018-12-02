#include <iostream> 
using namespace std;

long long jump(long long a, long long b, long long k){

	if(k == 1){
		return a;
	}
	if(k == 2){

		return a - b;
	}

	long long stepForward;
	long long value = 0;

	if(k %2 == 0){
		// so chan
		stepForward = k/2;

	}else{
		// so le
		stepForward = k/2 +1;
	}

	
	return a * stepForward - (k - stepForward) * b;
}

int main(){
	
	int t;
	long long a,b,k;
	cin >> t;

	for (int i = 0; i < t; ++i){
		cin >> a >> b >> k;
		cout << jump(a, b, k) << endl;
	}
	


	return 0;
}