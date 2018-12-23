#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(int argc, char const *argv[]){
	int n;
	cin >> n;
	while(n > 0){
		v.push_back(n%10);
		n/= 10;
	}

	reverse(v.begin(),v.end());
	
	int lastDegit = 0;
	for (int i = 0; i < v.size(); ++i){
		if(v[i] == 0){
			v.erase(v.begin()+i);
		}else{
			break;
		}
	}

	int lastNum = 1;
	int inc = 0;

	for (int i = 0; i < v.size(); ++i){
		inc ++;

		if(v[i] ==0 && lastNum == 0){
			continue;
		}
		cout << v[i];

		if(((int)v.size() - 1 - i) %3 ==0 && i < v.size()-1){
			cout << ",";
			inc = 0;
		}
		
		lastNum = v[i];
	}

	return 0;
}