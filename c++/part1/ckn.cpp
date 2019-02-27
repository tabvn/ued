#include <iostream> 

using namespace std;
/*
+ k=n => 1
+ k =0 => 1
*/
long long ckn(int k, int n){	
	if(k == 0 || k== n){
		return 1;
	}
	return ckn(k-1, n-1) + ckn(k, n-1);
}
int main(){
	int k,n;
	cin >> k >> n;

	cout << ckn(k,n);
	return 0;
}