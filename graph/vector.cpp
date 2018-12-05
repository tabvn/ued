#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/graph/VECTOR.INP");
ofstream fo ("/Users/toan/ued/graph/VECTOR.OUT");
vector<int> v;

bool descSort(int a, int b){

	return a > b;
}

bool buocLap(int k){

	sort(v.begin(), v.end(), descSort);
	// bo di d1, va tru bot di 1 don vi trong d1 tiep theo
	int d1 = v[0];

	if(d1 == 0){
		return true;
	}
	if(d1 > k-1 || d1 < 0){
		return false;
	}

	v.erase(v.begin());

	if(v.size() < d1){
		d1 = (int) v.size();
	}

	for (int i = 0; i < d1; ++i){
		v[i] -= 1;
	}

	return buocLap(k-1);
}

bool isVectorDoThi(){
	
	int k = (int) v.size();
	return buocLap(k);

}

int main(){
		
	int n;
	int deg;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> deg;
		v.push_back(deg);
	}

	if(isVectorDoThi()){
		fo << "vecto do thi";

	}else{
		fo << "Khong phai vecto do thi";
	}

	fi.close();
	fo.close();

	return 0;
}