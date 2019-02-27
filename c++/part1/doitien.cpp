#include <iostream> 
using namespace std;

// 10, 5 , 2 ,1
int arr[4] = {10,5,2,1};
int v[4] = {0,0,0,0};

void doiTien(int n){
	int tmp = 0;
	for (int i = 0; i < 4; ++i){
		tmp = n/arr[i];
		v[i] = tmp;
		n -= tmp * arr[i]; 
	}	
}
int main(){
	
	int n;
	cin >> n;
	doiTien(n);	
	for (int i = 0; i < 4; ++i){
		cout << v[i] << " to " << arr[i] << "d";
		if(i < 3){
			cout << " + ";
		}
	}

	return 0;
}