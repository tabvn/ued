#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("TRACK.INP");
ofstream fo ("TRACK.OUT");

vector<long long> v;

int main(){

	long long n,t,x;

	long long total = 0;
	long long sum = 0;

	fi >> n >> t;

	for (long long i = 0; i < n; ++i){
		fi>>x;
		v.push_back(x);
	}

	for (long long i = 0; i < v.size(); ++i){
		if(v[i] > t){
			continue;
		}else{
			total++;
		}

		sum = v[i];

		for (int j = i+1; j < v.size(); ++j){
			sum += v[j];

			if(sum > t){
				// qua suc xu ly tan rac
				break;

			}else{
				total++;
			}
		}
	
		// kiem tra lai tong tan rac neu vuot qua ta bo qua 
		if(sum > t){
			continue;
		}

	}

	fo << total;


	fi.close();
	fo.close();

	return 0;
}
