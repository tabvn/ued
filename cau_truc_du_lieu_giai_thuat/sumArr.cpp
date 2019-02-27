#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int LEN = 4;

int arr[LEN] = {3,1,9,3};


int sum(int index){

	if(index == LEN){
		return arr[index];
	}

	return arr[index] + sum(index+1);
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

int maxNum(int index){

	if(index == 0){
		return arr[index];
	}

	return max(arr[index], maxNum(index-1));
}



int main(){

	cout << sum(0) << endl; 
	cout << maxNum(LEN-1);
	return 0;
}