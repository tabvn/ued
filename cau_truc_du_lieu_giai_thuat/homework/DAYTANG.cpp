#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;


long int solve(){

	if(v.size() == 0){
		return 0;
	}
	if(v.size() == 1){
		return 1;
	}

	long int max = 0;
	long int maxSofar = 1;

	for (long int i = 1; i < v.size(); ++i){
		if(v[i] >= v[i-1]){
			
			maxSofar ++;
		}else{
			if(maxSofar > max){
				max = maxSofar;
			}
			maxSofar = 1;
		}

	}

	if(maxSofar > max){
		max = maxSofar;
	}

	return max;
}
int main(){
	
	long int n;
	long long tmp;
	cin >> n;



	for (long int i = 0; i < n; ++i){
		cin >> tmp;
		v.push_back(tmp);
	}

	cout << solve();

	return 0;
}