#include <iostream>
#include <iomanip>
using namespace std;

#include<iostream>
#include <iomanip>
using namespace std;

void sinxTien(){
    double x,epsilon,sinx,so;
    cin>>x>>epsilon;
    int k=1;
    double so_hang_k=x;
    sinx=so_hang_k;
    while(so_hang_k>=epsilon){
        k++;
        so=2*k-1;
        so_hang_k=(so_hang_k*x*x)/so/(so-1);
        if (k%2==0) sinx-=so_hang_k;
        else sinx+=so_hang_k;
    }
    cout<<fixed<<setprecision(4);
    cout<<sinx<<endl;
    //return 0;
}

double chia(double x, int n){

	if(n == 0){
		return x;
	}

	double value = 1;
	for (int i = 1; i <= 2*n +1; ++i){
		value *= double(x/i);
	}

	return value;
}

double toRadian(double x){
	/* 3.14 -> 180
		?      <- x
	*/

	double PI = 3.14159265359;
	return double((x/180) *PI);
}

double sinX(double x, double e){
	//x = toRadian(x);

	double value = 0;
	long int i = 0;
	double thuong = 0;
	while(true){
		thuong = chia(x, i);

		if(i%2==0){
			// chan dau +, le thi mang dau -
			value += thuong;
		}else{
			value -= thuong;
		}

		if(thuong <= e){
			break;
		}
		i++;
	}
	return value;
}

int main(){
	double x, e;
	cin >> x >> e;
	cout << fixed << setprecision(4) << sinX(x, e);
	return 0;
}