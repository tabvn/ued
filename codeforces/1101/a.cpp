#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void solve(long int l, long int r, long int d){

	if(d *1 < l){
		cout << d << endl;
		return;
	}
	
	if(d *2 < l){
		cout << d *2 << endl;
		return;
	}

	if(d *1 > r){
		cout << d << endl;
		return;
	}

	if(d*2 > r){
		cout << d *2 << endl;
		return;
	}

	int num = 2;
	while(true){

		if(d*num > r){
			cout << d *num << endl;
			break;
		}
		num++;

	}


}


int main(){

	int n;
	long int l,r,d;

	cin >> n;


	for (int i = 0; i < n; ++i){
		cin >>l >> r >> d;
		solve(l,r,d);
	}

	return 0;
}