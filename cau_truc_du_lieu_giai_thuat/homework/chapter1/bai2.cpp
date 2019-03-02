/*
Viết hàm đếm số chữ số của một số nguyên dương n theo hai cách: đệ quy và ko đệ quy
*/

#include <iostream>
using namespace std;

int count(int n){
	int total = 0;
	while(n > 0){
		n /= 10;

		total++;
	}

	return total;
}

int recusiveCount(int n, int total){

	if(n == 0){
		return total;
	}
	return recusiveCount(n/10, total +1);
}


int main(){
	
	int n;

	cout << "Nhap so nguyen duong N: ";

	cin >> n;

	cout << "Dem theo cach khong de quy:" << count(n) << endl;

	cout << "Dem theo cach dung de quy: " << recusiveCount(n, 0);
	return 0;
}