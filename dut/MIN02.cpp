#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> arr;

long long findMinNumber(int l, int r){
	
	long long min = arr[l-1];

	if(r > arr.size()){
		r = (int)arr.size();
	}
	for (int i = l-1; i < r; ++i){
		if(arr[i] < min){
			min = arr[i];
		}
	}

	return min;
}


int main(){

	int n,k,q,l,r;
	long long a;
	

	cin >> n >> k;

	for (int i = 0; i < n; ++i){
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < k; ++i){
		cin >> q >> l >> r;
		if(q == 1){
			// find Min from left to right
			cout << findMinNumber(l,r) << endl;
		}
		if(q == 2){
			arr[l-1] = r;
		}
	}
	return 0;
}