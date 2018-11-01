#include <iostream> 
#include <math.h>
#include <iomanip>
using namespace std;

/*
	e^x = x^0/0! + x^1/1! + ... x^n/n!
*/

double chia(double x, double ep, int n){
	double result = 1;
	for (int i = 1; i <= n; ++i){
		result = result* x/i;
	}
	return result;
}

double ex(double x, double ep){
	// 2 0.0001
	int i = 0;
	double value = 0;
	double ketQuaChia;
	while(true){
		ketQuaChia = chia(x, ep, i);
		value += ketQuaChia;
		i++;
		if(ketQuaChia <= ep){
			break;
		}

	}
	return value; 
}


int main(){
	double x, ep;
	char question;
	
	// tiép tuc lặp lại khi người dùng nhập ký tự khác C or c
	while(true){
		cout << "Nhap vao x, epsilon: ";
		cin >> x >> ep;
		cout << "Ket qua: e^" << x << " = ";
		cout << fixed << setprecision(4) << ex(x, ep);

		cin >> question;
		if(question != 'c' && question != 'C'){
			break;
		}
	}
	return 0;
}