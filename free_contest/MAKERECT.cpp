#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

vector<long int> v;

bool descSort(long int a , long int b){
	return a > b;
}

int main(){

	int n;
	long int a;
	long int x, y;

	x = 0;
	y = 0;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}
		
	sort(v.begin(), v.end(), descSort);
	int _index = 0;

	while(_index < v.size() - 1){
		if(v[_index] == v[_index +1] && v[_index] != 0){
			if(x == 0){
				x = v[_index];
				_index ++;
			}else{
				y = v[_index];
				break;
			}
		}
		_index++;
	}
	cout << (x*y);

	return 0;
}