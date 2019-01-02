#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("BASE.INP"); // file input
ofstream fo("BASE.OUT"); // file output

int main(){

	long long n;

	fi >> n;

	long long m = n;
	long long x = 2;
	int lastDiv = -1;

	while(m > 0){

		if(lastDiv != -1 && m % x != lastDiv){
			x++;
			m = n;
			lastDiv = - 1;
		}

		lastDiv = m %x;
		m /= x; 


	}

	cout << x;
	fi.close();
	fo.close();

	return 0;
}