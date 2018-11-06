#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n){
	if(n <2){
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

int reverse(int n){
	int s;
	while(n >0){
		s += s*10 + n%10;
		n /= 10;
	}

	return s;
}
void displayCoupleOfNumber(int n){
	int b = 0;
	int tmp = sqrt(n);
	int a = tmp;
	while(true){
		if(a<=0 || b >= tmp){
			break;
		}
		if(a*a + b*b < n){
			cout << "(" << a << ", "<< b<< ")" << endl;
			cout << "(" << b << ", "<< a<< ")" << endl;
			b++;
		}else{
			a--;
			b = 0;

		}

	}
}
int main(){
	int n;

	cin >> n;

	//cout << n << " Reverse:" << reverse(n);
	displayCoupleOfNumber(n);

	return 0;
}