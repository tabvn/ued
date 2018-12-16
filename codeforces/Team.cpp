#include <iostream> 
using namespace std;

int main(){
	int n,a;
	cin >> n;

	int total = 0;
	int peopleUnderstand;

	for (int i = 0; i < n; ++i){
		
		peopleUnderstand = 0;
		for (int i = 0; i < 3; ++i){
			cin >> a;
			if(a == 1){
				peopleUnderstand++;
			}
		}
		if(peopleUnderstand >=2){
			total ++;
		}


	}

	cout << total;

	return 0;
}