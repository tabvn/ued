#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("COMBIN.INP"); // file input
ofstream fo("COMBIN.OUT"); // file output

int arr[20];
int n , k, m;


int increaseIndex = -1;

void ghiNghiem(){

	increaseIndex ++;
	if(increaseIndex == m){
		for (int i = 1; i <= k; ++i){
			cout << arr[i] << " ";
		}
	}

}

void tohop(int i){

	for (int j = arr[i-1]+1; j <= n-k+i; ++j){

		
		arr[i] = j;

		if(i == k){
			ghiNghiem();
		}else{
			tohop(i+1);
		}


	}
}

int main(){

	fi >> n >> k >> m;

	arr[0] = 0;
	tohop(1);

	fi.close();
	fo.close();



	return 0;
}