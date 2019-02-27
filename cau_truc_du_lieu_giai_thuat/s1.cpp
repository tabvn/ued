#include <iostream>
#include <vector>
using namespace std;


int main(){
	
	int x;
	int n;

	cin >> n >> x;


	long long nArr[n+1];
	long long xArr[n];
	nArr[0] = 1;
	xArr[0] = 1;
	long long nGt = 1;
	long long p = 1;

	for (int i = 1; i <=n; ++i){
		nGt *= i;
		nArr[i] = nGt;
		p*= p;
		xArr[i] = p;
	}

	double s = 1+x;
	
	for (int i = 2; i <= n; ++i){
		double t = xArr[i] * (double)nGt/nArr[i];
		s += t/nGt;
	}

	cout << s;

	
	return 0;
}