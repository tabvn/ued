#include <iostream> 
using namespace std;


int ucln(int n, int m){
	if(n %m == 0){
		return m;
	}else if(m % n == 0){
		return n;
	}
	else{
		while(m != n){
			if(n > m){
				m = m;
				n = n -m;
			}
			if(m > n){
				n = n;
				m = m-n;
			}
		}
	}

	return m;
}

int main(){
	
	int n, m;

	cin >> n >> m;


	cout << ucln(n, m);

	return 0;
}