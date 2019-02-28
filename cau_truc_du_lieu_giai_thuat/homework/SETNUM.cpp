#include <iostream>
#include <algorithm>
using namespace std;


void solve(int *a, int n){
	
	 sort(a+0, a+n); // sap xep tang dan

	 int total = n;

	 int inc = 1;

	 // dem so lan xuat hien va tru di + 1
	 for (int i = 1; i < n; ++i){
	 		if(a[i] == a[i-1]){
	 			inc ++;
	 		}else{
	 			inc = 1; 
	 		}

	 		total = total - inc + 1;

	 }

	 cout << total;
}


int main(){


	int n;
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	solve(a, n);


	return 0;
}