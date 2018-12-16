#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fi("/Users/toan/ued/thuchanh10/input.txt");
ofstream fo("/Users/toan/ued/thuchanh10/output.txt");

vector<int> pArr;
vector<int> nArr;
vector<int> zeroArr;

bool ascSort(int a, int b){
	return a < b;
}

bool descSort(int a, int b){
	return a > b;
}

void addNum(int n){
	if(n > 0){
		pArr.push_back(n);
	}
	else if (n < 0){
		nArr.push_back(n);
	}else{
		zeroArr.push_back(n);
	}
}

void printArr(vector<int> v){

	for (int i = 0; i < v.size(); ++i){
		fo << v[i] << " ";
	}

}
void solve(){
	if(pArr.size() > 0){
		sort(pArr.begin(), pArr.end(), ascSort);
	}
	if(nArr.size() > 0){
		sort(nArr.begin(), nArr.end(), descSort);
	}

	printArr(pArr);
	printArr(zeroArr);
	printArr(nArr);
	
}

int main(){

	int n, num;

	fi >> n;

	for (int i = 0; i < n; ++i){
		fi >> num;
		addNum(num);
	}

	solve();

	fi.close();
	fo.close();

	return 0;
}