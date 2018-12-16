#include <iostream> 
using namespace std;


int main(){
	int n,k;

	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	cin >> k;

	for (int i = 0; i < n; ++i){
		if(i != k){
			cout << arr[i] << " ";
		}
	}
	return 0;
}