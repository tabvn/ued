#include <iostream>
using namespace std;

int main(){
	
	long long a,b,c;
	long long m;

	cin >> a >> b >> c;
	m = a;
	if(b < m){
		m = b;
	}
	if(c < m){
		m = c;
	}
	cout << m;
	
	return 0;
}