#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

ifstream fi ("MONEY.INP");
ofstream fo ("MONEY.OUT");

vector<long long> v;

int main(){


	long long m, a;
	long long sum;
	long long k, total;

	fi >> m >> k;

	total = 0;
	
	for (int i = 0; i < k; ++i){
		fi >> a;
		v.push_back(a);
	}

	sum = 0;
	for (int i = 0; i < k; ++i){
		sum += v[i];
		
		if(sum >= m){
			sum = sum%m;
			
			total ++;
		}
		
	}

	
	fo << total;

	fi.close();
	fo.close();

	return 0;
}