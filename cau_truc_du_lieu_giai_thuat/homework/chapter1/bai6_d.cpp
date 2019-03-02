#include <iostream>
#include <math.h> 
using namespace std;

long double *a;

double toRadial(int x){
	return x*3.14159265359/180;
}

long double p(double sinx, int n){

		long double v = a[n];

		if(v != -1){
			return v;
		}

		v = 1;
		for (int i = 1; i <= n; ++i){
			v*= sinx;
			a[i] = v;
		}
		

		return v;
}

long double tongSin(int n, double x){

	long double s = 0;
	long double sinX = sin(x);
	for (int i = n; i >=0; --i){
		long double v = a[i];
		s+= p(sinX, i);
		
	}

	return s;

}

long double tongSinDequy(int n, double x){

	if(n== 0){
		return 1;
	}

	long double sinX = sin(x);

	return p(sinX, n) + tongSinDequy(n-1, x);
}

int main(){
	

	int n;
	int x;
	cout << "Nhap N: ";
	cin >> n;
	// khoi tao mang cached
	a = new long double[n+1];
	for (int i = 0; i <= n; ++i){
		a[i] = -1;
	}

	cout << "Nhap X (degree): ";

	cin >> x;

	cout << "Ket qua khong dung de quy: " << tongSin(n,toRadial(x)) << endl;

	cout << "Ket qua dung de quy: " << tongSinDequy(n,toRadial(x));
	return 0;
}