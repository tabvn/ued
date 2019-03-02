#include <iostream>
using namespace std;

struct PhanSo
{
	long long tu,mau;

	PhanSo(long long tu, long long mau){
		this->tu = tu;
		this->mau = mau;
	}

	long long gcd(long long a, long long b){
		if(a %b == 0){
			return b;
		}
		if(b%a == 0){
			return a;
		}
		while(a != b){
			if(a > b){
				a = a-b;
			}else{
				b = b -a;
			}
		}

		return a;
	}
	PhanSo operator + (const PhanSo &b){


		// 1/2 + 1/3
		long long tuSo, mauSo;

	
		tuSo = (this->tu * b.mau) + b.tu * this->mau;
		mauSo = this->mau * b.mau;
		long long uc = this->gcd(tuSo, mauSo);
		return PhanSo(tuSo/uc, mauSo/uc);
	}

	void print(){
		cout << this->tu << "/" << this->mau;
	}

};


void sum(int n){

	PhanSo p(1,1);


	for (int i = 2; i <= n; ++i){
		p = p + PhanSo(1, i);
	}

 	p.print();
}

PhanSo recurseSum(int n){
	if(n == 1){
		return PhanSo(1, 1);
	}
	return PhanSo(1, n) + recurseSum(n-1); 
}

int main(){
	
	int n;

	cout << "Nhap N: ";
	cin >> n;

	cout << "Tinh tong phan so khong dung de quy: ";
	sum(n);
	cout << endl;

	cout << "Tinh tong phan so dung de quy: ";

	PhanSo kq = recurseSum(n);
	kq.print();


	return 0;
}