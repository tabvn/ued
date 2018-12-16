#include <iostream> 
using namespace std;

bool isLucky(int n){
	int divisble;
	while(n > 0){
		divisble = n%10;
		if(divisble != 4 && divisble != 7){
			return false;
		}
		n/= 10;
		
	}

	return true;
}
bool isLuckyNumber(int n){
	if(n %4 == 0 || n%7 == 0){
		return true;
	}
	if (isLucky(n)){

		return true;
	}else{

		for (int i = 4; i <= n; ++i){
				if(isLucky(i) && n %i == 0){
					return true;
				}
		}

	}

	
	return false;
}

int main(){

	int n;

	cin >> n;

	if(isLuckyNumber(n)){
		cout << "YES";
	}else{

		cout << "NO";
	}
	return 0;
}