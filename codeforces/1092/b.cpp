#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool ascSort(int a, int b){

	return a < b;
}
int main(int argc, char const *argv[]){
	
	int n,a;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), ascSort);

	int total = 0;

	for (int i = 0; i < v.size(); i=i+2){
		total += v[i+1] - v[i];
	}

	cout << total;

	return 0;
}