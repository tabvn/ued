#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long int n){
	if(n < 2){
		return false;
	}

	for(int i =2 ; i<= sqrt(n); i++){
		if(n % i == 0){
			return false;
		}
	}

	return true;

}


int so(int len, bool isMin){
	if(isMin){
		return pow(10, len-1);
	}
	return pow(10, len) -1;
}


int xoaSo(int n, int len){
	while(len > 0){
		n /=10;
		len--;
	}

	return n;
}
int timSo(int n){

	int total = 0;
	int num = so(n, false);
	int minNum = so(n, true);

	for (int i = minNum; i < num; ++i){
		if(isPrime(i)){

			if(n > 1){
				bool snt = true;
				for (int j = 1; j < n; ++j){
					int x = xoaSo(i, j);
					
					if(!isPrime(x)){
						snt = false;
					}
				}

				if(snt){
					total++;
				}
			}
		}
	}

	return total;
}

int main(){

	int n;
	
	cin >> n;

	cout << timSo(n);
	return 0;
}
