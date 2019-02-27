#include <iostream> 
using namespace std;

/*
n = 1 => m = 0
a(m-1, 1) => n=0;
*/
int a(int m, int n){
	if(m == 0){
		return n+1;
	}
	if(n == 0){
		return a(m-1, 1);
	}
	return a(m-1, a(m,n-1));
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << a(m,n);
	return 0;
}