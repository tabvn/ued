#include <iostream> 
using namespace std;

void phanTich(int n){
	for (int i = 2; i <= n; ++i){
		while(n%i == 0){
			cout << i << endl;
			n/=i;
		}
	}
}
int main(){
	
	int n;

	cin >> n;

	phanTich(n);

	return 0;
}