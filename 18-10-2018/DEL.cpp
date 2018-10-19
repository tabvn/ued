#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("DEL.INP");
ofstream fo ("DEL.OUT");

vector<long int> v;

int main(){
	int n;
	long int a;
	long long sum;

	int chan = 0;
	int le = 0;
	int tongSoLe = 0;

	long long total = 0;

	fi >> n;

	for (int i = 0; i < n; ++i){
		fi >> a;

		if(a%2 == 0){
			chan++;
		}else{
			le++;
		}
		v.push_back(a);
	}

	for (int i = 0; i < v.size(); ++i){
		for (int j = i+1; j < v.size(); ++j){

			tongSoLe = le;
			if(v[i] %2 != 0){
				// them 1 so le
				tongSoLe --;
			}
			if(v[j] %2 != 0){
					// them 1 so le
				tongSoLe --; 
			}
			// neu thanh phan le la so chan, thi tong la chan
			if(tongSoLe %2 == 0){
				// tong se la 1 so chan
				total++;
			}
		}
	}

	fo << total;

	fi.close();
	fo.close();

	return 0;
}