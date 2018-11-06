#include <iostream> 
#include <math.h>
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/RATEEQUA.INP");
ofstream fo ("/Users/toan/ued/RATEEQUA.OUT");

long long fn(int n){	

	long long s = 0;
	if(n == 2 || n == 1){
		return 1;
	}
	return fn(n-1) + fn(n-2);
}

long long fn1(int n){
	return (pow(1+sqrt(5),n) - pow(1-sqrt(5),n))/(pow(2,n)*sqrt(5));
}
void doJob(int n, int a){

}
int main(){
	long long a,n;
	fi >> a >> n;

	cout << fn(n);
	cout << fn1(99);

	return 0;
}