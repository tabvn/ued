#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	int n,m;

	cin >> n;
	int arr[n];

	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	cin >> m;

	int total = 0;

	for (int i = 0; i < n; ++i){
		if(arr[i] == m){
			total ++;
			v.push_back(i);
		}
	}

	if (total == 0){
		cout << "NotFound";
	}else{
		cout << total << ": ";
		for (int i = 0; i < v.size(); ++i){
			cout << v[i] << " ";
		}
	}

	return 0;
}