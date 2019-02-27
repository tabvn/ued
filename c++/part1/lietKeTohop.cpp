#include <iostream>
using namespace std;

const int MAX = 20;

int a[MAX];
int k = 3;
int n = 6;

int arr[] = {4,5,6,7,8,9};

void ghiNghiem(){
	for (int i =1; i <= k; ++i){
		cout << arr[a[i]-1];
		if(i < k){
			cout << ",";
		}
	}
	cout << endl;
}
void tohop(int i){

	for (int j = a[i-1] + 1; j <= n-k+i; ++j){
		a[i] = j;
		if(i == k){
			ghiNghiem();
		}else{
			tohop(i+1);
		}
	}
}
int main(){

	a[0] = 0;
	tohop(1);

	return 0;
}
