#include <iostream>
#include <iomanip>
using namespace std;

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
	double PI = 3.14159265359; // dài mới tốt nha, nếu dung 3.14 sẽ sai số rất lớn
	return double((x/180) *PI);
}

double sinX(double x){
	x = toRadian(x);

	double value = 0;
	long int i = 0;
	double thuong = 0;
	while(true){
		thuong = chia(x, i);
		if(i%2==0){
			// chan dau +
			value += thuong;
		}else{
			value -= thuong;
		}

		if(thuong <= 0){
			break;
		}
		i++;
	}
	return value;
}

int main(){
	double x;
	cin >> x;
	cout << fixed << setprecision(4) << sinX(x);
	return 0;
}