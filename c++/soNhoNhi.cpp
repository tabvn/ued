#include <iostream> 
using namespace std;

int main(){

	int n;
	int minNum;
	int secondMinNum; 

	for (int i = 0; i < 4; ++i){
		cin >> n;
		if(i == 0){
			minNum = n;
			secondMinNum = n;
		}else{
			if(n < minNum){
				secondMinNum = minNum;
				minNum = n;
			}
		}

	}

	cout << secondMinNum;

	return 0;
}