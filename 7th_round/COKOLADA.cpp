#include <iostream> 
#include <math.h>
using namespace std;


int findNum(int n){
	int deg = 0;
	int num;
	while(true){
		num = pow(2,deg);

		if(num >= n){
			break;
		}
		deg++;
	}

	return num;
}

int main(){
	int k;
	cin >> k;

	int theNumber = findNum(k); // ta tim dc so can chia
	int barNum = theNumber;
	// tien hanh cat banh lam sao cho dc k
	int total = 0;
	int left = 0;

	int numOfBreaks = 0;
	if(barNum == k){
		cout << barNum << " " << numOfBreaks;
	}else{

		while(true){
			//tien hanh chia banh
			left = barNum/2;

			// mieng thua cong vao ma > k ta tieo tuc cat doi
			if(total +left > k){

				barNum /=2;
				numOfBreaks++;
		
			}else{

				total += barNum/2;
				numOfBreaks++;
				barNum /= 2;
				//cout << "chia:" << barNum << " total:" << total << " b:" << numOfBreaks << endl;

			}
			
			if(total == k){
				break;
			}

		}
	
		cout << theNumber << " " << numOfBreaks;
	}
	

	return 0;
}