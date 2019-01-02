#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


bool isUnique(int n){

	vector<int> v;
	while(n > 0){
		v.push_back(n%10);
		n/= 10;
	}

	for (int i = 0; i < v.size(); ++i){
		
		for (int j = 0; j < v.size(); ++j){
			if(i == j){
				continue;
			}
			if(v[j] == v[i] ){
				return false;
			}
		}
	}

	return true;
}
void solve(int n){
	n+= 1;
	while(true){
		if(isUnique(n)){
			break;
		}
		n += 1;
	}

	cout << n;


}

int main(){
	int y;

	cin >> y;

	solve(y);
	return 0;
}