#include <iostream>
using namespace std;

int daoSo(int n){
	
	int ds = 0;
	int tmp;
	while(n > 0){
			 tmp = n%10;
			 ds = ds * 10 + tmp;
			 n/= 10;
	}

	return ds;
}

int daoSoDequy(int n, int kq){

	if(n == 0){
		return kq;
	}

	return daoSoDequy(n/10, kq*10+n%10);
}

int main(){
	int n;

	cout << "Nhap vao N: ";
	cin >> n;
	cout << "So dao nguoc cua N: " << daoSo(n) << endl;
	cout << "So dao nguoc cua N dung de quy: " << daoSoDequy(n, 0);
	return 0;
}