#include <iostream>
using namespace std;

// use vector is more better :)

int len = 0;
int *arr = new int[1];

void add(int n){

	int *newArr = new int[len+1];

	// copy items from old to new
	if(len > 0){
		for (int i = 0; i < len; ++i){
			newArr[i] = arr[i];
		}
	}
	
	newArr[len] = n; 
	delete [] arr;
	arr = newArr;
	len ++;
	
}


int digit(int n, int k){

	while(n > 0){
			add(n%10);
			n /= 10;
	}

	if(k > len){
		return 0;
	}

	return arr[k-1];
}
int main(){
	int n, k;
	cin >> n >> k;

	cout << digit(n,k);

	return 0;
}