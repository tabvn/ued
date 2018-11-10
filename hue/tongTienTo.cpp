#include <iostream> 
#include <vector>
using namespace std;

vector<int> v;

int main(){
	int t,a;

	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> a;
		v.push_back(a);
	}

	long long s = 0;
	bool hasSumTotalZero = false;
	for (int i = 0; i < v.size(); ++i){
		s = v[i];

		for (int j = i+1; j < v.size(); ++j){
			s += v[j];
			if(s == 0){
				hasSumTotalZero = true;
				break;
			}
		}
	}

	if(hasSumTotalZero){
		cout << "YES";
	}else{
		cout << "NO";
	}

	return 0;
}