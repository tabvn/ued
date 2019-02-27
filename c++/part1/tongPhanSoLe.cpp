#include <iostream> 
#include <iomanip>
using namespace std;

double chia(double x, int n){
	if(n == 0){
		return x;
	}
	
	double value = 1;

	for (int i = 1; i <= (2*n+1); ++i){
	
		value *= double(x/i);
	}

	return value;
}
int main(){

	double x,thuong;
	double s = 0; 
	cin >> x;

	int n = 0;

	while(true){
		thuong = chia(x, n);

		if(thuong == 0){
			break;
		}
		if(n %2 == 0){
			// chan thi (-1)^n => +
			s += thuong;
		}else{
			s -= thuong;
		}
		n++;
	}

	cout << fixed << setprecision(4) << s;
	return 0;
}