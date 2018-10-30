#include <iostream> 
using namespace std;

/*
Bậc của thừa số nguyên tố trong n! giai thừa
*/
int deg(long int n, long int p){
	int d = 0;
	while(n > 0){
		n /= p;
		d+= n;
	}

	return d;
}

int main(){
	long int n,p;
	cin >> n >> p;
	cout << deg(n, p);
	return 0;
}