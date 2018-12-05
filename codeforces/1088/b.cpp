#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

vector<long int> v;
int n,k;

bool sortAsc(long int a, long int b){
	return a < b;

}
void solve(){

	sort(v.begin(), v.end(), sortAsc);

	bool isStopped = false;

	long int x;
	for (int i = 0; i <= k; ++i){
		
		for (int j = 0; j < v.size(); ++j){
			if(v[j] > 0){
				x = v[j];
				break;
			}
		}

		if(v[(int)v.size()-1] == 0){
			cout << 0 << endl;
			break;

		}else{

			cout << v[i] << endl;
			for (int j = 0; j < v.size(); ++j){
				
				if(v[j] > 0){
				cout << "x:" <<x << endl;
					v[j] -= x;
				}
			}
		}


	}

}


int main(){
	
	long int ai;

	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> ai;
		v.push_back(ai);
	}

	solve();


	return 0;
}