#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

long long a,b;
///Users/toan/ued/16-10-2018/AUCTION
ifstream fi ("AUCTION.INP");
ofstream fo ("AUCTION.OUT");


bool isPrime(long long n){
	if(n < 2){
		return false;
	}
	bool snt = true;

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0){
			snt = false;
		}
	}
	return snt;

}



bool doiXung(long long n){
	bool dx = false;
	vector<long long> v;
	long long value = n;
	while(value > 0){
		v.push_back(value %10);
		value /= 10;
	
	}

	long long i,j;

	i = 0;
	j = v.size() - 1;

	while(v[i] == v[j]){

	
		i++;
		j--;

		if(i >= j){
			dx = true;
		}
	}

	return dx;
}

int main(){


	fi >> a >> b;

	long long increase = 0;
	for (int i = a; i <=b; ++i){
		if(isPrime(i) && doiXung(i)){
			increase++;
		}
	}
	fo << increase;

	fi.close();
	fo.close();

	return 0;
}