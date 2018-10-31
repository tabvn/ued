#include <iostream> 
#include <fstream>
using namespace std;

ifstream fi ("N3S.INP");
ofstream fo ("N3S.OUT");

void findN3s(long long k, long long m){
	long long inc = 0;
	long long num = 0;
	long long le = 1;
	while(inc <= k-1){ // dem tu 0
		if((num -1) %3 ==0){
			inc++;	

			if(inc == k){
				break;
			}
		}
		num = num +le;
		le+= 2;
	}
	fo << ((num -1) % m);

}


int main(){
	
	int t;
	long long k,m;
	fi >> t;
	for (int i = 0; i < t; ++i){
		fi >> k >> m;
		findN3s(k,m);
		if(i < t-1){
			fo << endl;
		}
	}


	fi.close();
	fo.close();

	return 0;
}