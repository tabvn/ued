#include <iostream> 
using namespace std;

int ucln(int a, int b){
	if(a %b == 0){
		return b;
	} 
	if(b%a == 0){
		return a;
	}
	while(a != b){
		if(a > b){
			b = b;
			a = a-b;
		}else{
			a = a;
			b = b-a;
		}
	}


	return a;
}

int main(){
	/*
		4
		1 3 5 9
	*/

	int n, x;
	int lastUc;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		
		if(i == 0){
			lastUc = x;
			continue;
		}
		lastUc = ucln(x, lastUc);

	}

	cout << lastUc;

	return 0;
}