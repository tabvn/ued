#include <iostream>
#include <vector>


using namespace std;

vector<long long> v;


int main(){

	long long n,k,a;

	long long sum = 0;
	long long total = 0;

	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);

	}

	for (int i = 0; i < v.size(); ++i){
		sum = v[i];

		if(sum == k){
			total ++;
			sum = 0;
			continue;
		}

		if(sum >k){
			sum = 0;
			continue;
		}

		for (int j = i+1; j < v.size(); ++j){
			sum += v[j];
			if(sum == k){
				total ++;
			}
			if(sum > k){
				
				break;
			}
			
		}

		if(sum > k){
			sum = 0;
			continue;
		}
		if(sum == k){
			total ++;
		}

	}

	cout << total;

	return 0;
}