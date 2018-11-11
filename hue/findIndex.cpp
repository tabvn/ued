#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long n = 1;
vector<int> degits;

void write(){


	long long tmp;
	vector<int> v;

	for (int i = 0; i < 100000; ++i){
		
		tmp = n;
		v.clear();
		while(tmp > 0){
			v.push_back(tmp%10);
			tmp/=10;
		}
		for (int i = v.size() -1; i >= 0; --i){
			degits.push_back(v[i]);
		}

		n++;
	}

}

void print(){

	for (int i = 0; i < degits.size(); ++i){
		cout << degits[i] << " ";
	}
}
// find index of number in the wrting array
long long findIndex(long long number){
	vector<int> v;
	bool allSame = false;
	while(number > 0){
		v.push_back(number%10);
		number /=10;
	}

	reverse(v.begin(), v.end());

	while(true){
		write();
		for (int i = 0; i < degits.size(); ++i){
			if(degits[i] == v[0]){
				// so dau tien trung nhau ta tim kiem so ke tiep
				allSame = true;
				for (int j = 1; j < v.size(); ++j){
					
					if(i+j > (int) (degits.size()-1) || v[j] != degits[i+j]){
						// khac nhau dunglai
						allSame = false;
						break;
					}
				}
				// kiem tra lai
				if(allSame){
					// tim thay vi tri
					//print();
				
					return i;
				}
			}
		}
	}
	

}

int main(){

	int t,a;
	cin >> t;
	vector<int> v;
	for (int i = 0; i < t; ++i){
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); ++i){
		cout << (findIndex(v[i]) +1) << endl;
	}
	
	return 0;
}