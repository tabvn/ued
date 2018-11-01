#include <iostream>
#include <math.h>

using namespace std;

long long daoSo(long long n, long long s){
	if(n == 0){
		return s;
	}
	return daoSo(n/10, s*10 + n%10);
}
int main(){

	long int n;
	cin >> n;
	long int value = daoSo(n,0);
	cout << "So dao: ";
	cout << value;
	cout << " ";
	cout << value * 2;

	return 0;

}