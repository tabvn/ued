#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

void addNum(int n){

	v.push_back(n);
}

void solve(){

	int maxNum;
	int minNum;
	int minLe;

	bool chan = false;
	int tmp;

	for (int i = 0; i < v.size(); ++i){

		chan = v[i] %2 == 0;

		for (int j = 0; j < v.size(); ++j){

			if(chan){
				if(v[j] %2 == 0 && v[j] > v[i]){
					tmp = v[j];
					v[j] = v[i];
					v[i]= tmp;
				}
			}else{

				if(v[j] %2 != 0 && v[j] < v[i]){
					tmp = v[j];
					v[j] = v[i];
					v[i]= tmp;
				}

			}
		}
	}


	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
}


int main(){
	int n, num;
	cin >> n;
	
	for (int i = 0; i < n; ++i){
		cin >> num;
		addNum(num);
	}

	solve();

	return 0;
}