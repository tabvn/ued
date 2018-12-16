#include <iostream> 
using namespace std;

int solve(int n){
	int total = 0;

	if(n <= 7){
		return 1;
	}

	int inc = 2;
	int num = 7;
	bool isDivisble;
	while(true){

		if(n <=7){
			break;
		}

		isDivisble = false;
		
		for (int i = 7; i >= 2; --i){
			if((n - inc) %i == 0){

				

				n -= inc;
				if(inc >= 2){
						total++;
						inc =0;
				}

				total += n/i;
				n = 0;
				isDivisble = true;
				break;
			}
		}

		if(!isDivisble){
			inc ++;
		}
		

		


	}

	return total;

}
int main(){
	
	int n, a;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a;
		cout << solve(a);
		cout << endl;
	}

	return 0;
}