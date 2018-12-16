#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("so.txt");
ofstream fo("cacuoc.txt");


int main(){
	int n;
	fi >> n;

	fo << 1 << " ";
	for (int i = 2; i < n; ++i){
		if(n%i ==0){
			fo << i << " ";
		}
	}
	fo << n;
	
	fi.close();
	fo.close();
	
	return 0;
}