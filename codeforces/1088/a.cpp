#include <iostream> 
using namespace std;

void solve(int x){
	
	int a = x;
	int b;
	bool found = false;

	while(a >=1){

		for(int i = 1; i <=a; i++){
			if(a % i ==  0 && a*i > x && a/i < x){
				found = true;
				b = i;
				break;
			}
		}

		if(found){
			break;
		}
		a--;
	}

	if(found){
		cout << a << " " << b;
	}else{

		cout << -1;
	}
}
int main(){
	int x;

	cin >> x;

	solve(x);

	return 0;
}