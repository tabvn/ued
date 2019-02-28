#include <iostream>
#include <algorithm>
using namespace std;

bool isSymability(long long *a, int n){

	sort(a+0, a+n); // sort array

	// dem thanh phan xuat hien khong chia het cho 2

	int inc = 1;
	int count = 0;

	for (int i = 1; i < n; ++i){
			if(a[i] == a[i-1]){
				inc ++;
			}else{

				if(inc %2 != 0){
					count ++; // tang thanh phan xuat hien ma ko chia het cho 2
				}
				inc = 1;
			}
	}

	if(n %2 == 0){
		// neu so luong chan ma thanh phan xuat hien ko chia het cho 2 = 0 thi true
		if(count == 0){
			return true;
		}
	}else{
		// so luong le thi thanh phan ko chia het cho 2 = 1 thi true

		if(count == 1){
			return true;
		}
	}


	return false;


}

int main(){
	
	int n;
	cin >> n;
	long long *a = new long long[n];

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	if(isSymability(a, n)){
		cout << "TRUE";
	}else{
		cout << "FALSE";
	}
	return 0;
}