#include <iostream> 
#include <vector>

using namespace std;

vector<int> v;

void solve(int n){
	while(n > 0){
		v.push_back(n%2);
		n/= 2;
	}

	for (int i = (int)v.size()-1; i >=0 ; --i){
		cout << v[i];
	}
}
int main(){
	int n;
	cin >> n;

	solve(n);

	return 0;
}