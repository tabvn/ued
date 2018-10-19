#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fi("MUSEQ.INP");
ofstream fo("MUSEQ.OUT");

struct Test{
	vector<long int> v;

};

Test test;
vector<long int> vOut;
vector<Test> v;
vector<long int> vSort;


bool ascSort(long int a, long int b){
	return a < b;
}

void addVsort(){
		vSort.clear();
		// add to vsort
		for (int j = 0; j < test.v.size(); ++j){
			vSort.push_back(test.v[j]);
		}
		// sort vsort asc 
		sort(vSort.begin(), vSort.end(), ascSort);

}

// find index trong Test ban dau

int findIndex(long int n){
		for (int i = 0; i < vSort.size(); ++i){
			if(vSort[i] == n){
				return i;
			}
		}

		return -1;

}
int main(){

	int t,n;
	long int a;
	long int thIndex = -1;


	fi >> t >> n;

	int increase = 1;
	for (int i = 0; i < t; ++i){
			for (int j = 0; j < n ; ++j){
				fi >> a;
				test.v.push_back(a);
			}
			v.push_back(test);
	}

	// processing
	for (int i = 0; i < t ; ++i){
		test = v[i];
		addVsort();

		for (int j = 0; j < vSort.size(); ++j){
			vOut.push_back(increase);
			if(vSort[j+1] > vSort[j]){
				increase++;
			}

		}

		for (int j = 0; j < test.v.size(); ++j){
			thIndex = findIndex(test.v[j]);
			fo << vOut[thIndex];
			if(j < test.v.size() -1){
				fo << " ";
			}
		}	
		
		if(i < t-1){
			fo << endl; // xuong dong nhuong vi tri cho phan test tiep theo
		}

	}

	fi.close();
	fo.close();

	return 0;

}