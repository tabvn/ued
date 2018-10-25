#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
/Users/toan/ued/18-10-2018
*/

ifstream fi ("FIBSEQ.INP");
ofstream fo ("FIBSEQ.OUT");

vector<long int> v;


int checkArr(int vSize){

	int i, j;
	i = 2;
	j = vSize - 1;

	int fib = 0;

	while((v[i] == v[i-1] + v[i-2]) && v[j] == v[j-1] + v[j-2]){
		i++;
		j--;

		if(i >= j){
			fib = 1;
		}
	}

	return fib;
	
}

int main(){

	int n;
	long int a;

	fi >> n;

	for (int i = 0; i < n; i++){
		fi >> a;
		v.push_back(a);
	}

	fo << checkArr(n);

	fi.close();
	fo.close();

	return 0;
}