#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool solve(int n){

	while(n > 0){
		v.push_back(n%10);
		n/=10;
	}

	if(v.size() == 0){
		
		return true;
	}

	int len = (int) v.size();
	int lastNum = v[0];

	for (int i = 1; i < v.size(); ++i){
		if(v[i] >= lastNum){
			return false;
		}

		lastNum = v[i];
	}

	return true;
}
int main(){
	
	int n;
	cin >> n;

	bool res = solve(n);
	if(res){
		cout << "Tang dan";
	}else{

		cout << "Khong tang dan";
	}
	return 0;
}