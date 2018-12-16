#include <iostream>
#include <algorithm>

using namespace std;


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

void _remove(int index){

	int *newArr = new int[len-1];

	int inc = 0;

	if(len > 0){
		for (int i = 0; i < len; ++i){
			if(i != index){
				newArr[inc] = arr[i];
				inc++;
			}
			
		}
	}
	
	delete [] arr;
	arr = newArr;
	len --;
}

bool ascSort(int a, int b){
	return a < b;

}

void removeOdd(int length){

	for (int i = 0; i < length; ++i){
		if(arr[i]%2 != 0){
			_remove(i);
		}
	}


}
int main(){
	int n,a;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		add(a);

	}
	sort(arr, arr+n, ascSort);
	removeOdd(n);
	for (int i = 0; i < len; ++i){
		cout << arr[i] << " ";
	}

	return 0;
}