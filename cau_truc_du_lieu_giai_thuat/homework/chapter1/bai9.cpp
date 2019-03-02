// 8 quan hau
#include <iostream>
#include <math.h>
using namespace std;

int a[8];
const int n = 8;

bool isOK(int x, int y){

	for(int i = 1; i< x; i++ ){

		if(a[i] == y){
			// chung cột
			return false;
		}

		if(abs(a[i] - y) == abs(i-x)){
			// duong cheo // cong thuc copy
			return false;
		}

	}

	return true;
}

void print(){
	for (int i = 1; i <= n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

void Try(int i){

	for (int j = 1; j <= n; ++j){
		if(isOK(i, j)){
			// dat tai hang i cot j
			a[i] = j;
			if(i == n){
				print(); // in ra phuong an
			}
			Try(i+1); // tang hang len 1
		}
	}
}
int main(){
	
	Try(1);
	return 0;
}