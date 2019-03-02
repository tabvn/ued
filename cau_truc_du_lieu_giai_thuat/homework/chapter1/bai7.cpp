// to hop chap k cua n phan tu
#include <iostream>
using namespace std;

long long cn(int n, int k){

	if(k==0 || n == k){
		return 1;
	}

	return cn(n-1, k-1) + cn(n-1, k);
}
int main(){
	int n,k;

	cout << "Nhap N: ";
	cin >> n;
	cout << "Nhap K: ";
	cin >> k;

	cout << "Ket qua to hop chap k cua N la: " << cn(n, k);
	return 0;
}