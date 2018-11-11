#include <iostream>
#include <fstream>


using namespace std;
/*
/Users/toan/ued/16-10-2018/SP
*/

ifstream fi ("SP.INP");
ofstream fo ("SP.OUT");
int main(){

	long int m,n,t;
	long long sum;

	/**
		goi x la so but can phai tra tien
		khi mua m chiec thi duoc tang 1 chiec, vay mua x chiec se dc tang x/m
		x + x/m = n 
		=> x = (n*m)/(m+1)
	*/

	fi >> m >> n >> t;

	//sum = ((n*m)/(m+1)) *t;

	long long total = 0;
	long long totalNeedBuy = 0;
	long long inc = 0;

	while(true){
		total ++;
		totalNeedBuy++;
		inc++;
		if(inc == m){
			total++;
			inc = 0;
		}
		if(total == n){
			break;
		}	
	}

	fo << totalNeedBuy * t;

	return 0;

}