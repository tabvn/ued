#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
	
	int t;

	long long l,r;

	cin >> t;
	

	for (int i = 0; i < t; ++i){
		cin >> l >> r;

		if(l*2 > r){
				cout << l << " " << r << endl;
			}else{
				cout << l << " " << l*2 << endl;
		}
	}

	

	return 0;
}