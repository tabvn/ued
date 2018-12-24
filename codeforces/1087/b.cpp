#include <iostream> 
using namespace std;

int main(int argc, char const *argv[]){


	long long n,k,x;

	cin >> n >> k;

	x = 1;

	while(true){

		if((x/k * (x%k)) == n){
			cout << x << endl;
			break;
		}
		
		x++;
	}

	if(n % 2 != 0){
		cout << n*k + 1;
		return 0;
		
	}

	if(n%2 == 0 && k %2 == 0){
		if(k == 2){
			cout << n *k +1;
			return 0;
		}
		cout << n + k + n/k;
		return 0;
	}

	if(n%2 == 0 && k%2 != 0){
		cout << n + k + n/k;
		return 0;
	}


	return 0;
}