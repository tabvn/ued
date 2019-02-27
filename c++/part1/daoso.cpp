#include <iostream> 
using namespace std;

/*
Cách dùng đệ quy
*/
long long recursion(long long n, long long s){
	if(n == 0){
		return s;
	}
	return recursion(n/10, s*10 + n%10);
}

/*
cách không dùng đệ quy
*/
long long daoSo(long long n){
	long long s = 0;	
	while(n > 0){
		s = s*10 + n%10;
		n /= 10;
	}
	return s;

}
int main(){
	long long n;
	cin >> n;

	cout << recursion(n, 0);

	return 0;
}