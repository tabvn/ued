#include <iostream>
using namespace std;

bool isGoodNumber(long int n){

	long int total = 0;

	for (int i = 1; i < n; ++i)
	{
		if(n%i == 0){
			total += i;
		}	
	}

	if(total == n){
		return true;
	}

	return false;
	
}
int main(){

	long int n;
    
    cin >> n;

    if(isGoodNumber(n)){
    	cout << "So hoan hao";
    }else{
    	cout << "So khong hoan hao";
    }
	return 0;
}