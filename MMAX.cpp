#include <iostream> 
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fi ("MMAX.INP");
ofstream fo ("MMAX.OUT");

vector<int> v;
vector<int> v1;

bool ascSort(int a, int b){
	return a < b;
}

bool descSort(int a, int b){
	return a > b;
}

long long doCheck(){
	long long maxValue = 0;
	long long value;

	value = v[0] * v[1];
	if(value > maxValue){
		maxValue = value;
	}
	value = v[0]*v[1] * v[2];

	if(value > maxValue){
		maxValue = value;
	}

	value = v[0] * v1[0];

	if(value > maxValue){
		maxValue = value;
	}
	value = v[0]*v[1] * v1[0];

	if( value > maxValue){
		maxValue = value;
	}
	value = v[0]*v1[0] * v1[1];
	if( value > maxValue){
		maxValue = value;
	}

	value = v1[0]*v1[1] * v1[2];

	if( value > maxValue){
		maxValue = value;
	}

	return maxValue;

}


int main(){
	int n, a;


	fi >> n;

	long long maxValue = 0;
	for (int i = 0; i < n; ++i){

		fi >> a;
		v1.push_back(a);
		v.push_back(a);
	}

	sort(v.begin(), v.end(), descSort);
	sort(v1.begin(), v1.end(), ascSort);
	maxValue = doCheck();

	fo << maxValue;



	fi.close();
	fo.close();

	return 0;
}