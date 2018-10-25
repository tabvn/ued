#include <iostream>

using namespace std;

long int uocLN(long int a, long int b){

	if(a %b == 0){
		return b;
	}
	if(b%a == 0){
		return a;

	}
	
	while(a != b){
		if(a > b){
			a = a-b;
		}else{
			b = b-a;
		}
	}

	return a;
}

int main(){

	long int a,b;
    
    cin >> a >> b;

    cout << "Uoc chung lon nhat: " << uocLN(a, b);
    
	return 0;
}