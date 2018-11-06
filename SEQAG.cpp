#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;

ifstream fi ("/Users/toan/ued/SEQAG.INP");
ofstream fo ("/Users/toan/ued/SEQAG.OUT");

vector<int> v;

int main(){
	
	int n, a;
	fi >> n;

	for (int i = 0; i < n; ++i){
		fi >> a;
		v.push_back(a);
	}

	fi.close();
	fo.close();

	return 0;
}