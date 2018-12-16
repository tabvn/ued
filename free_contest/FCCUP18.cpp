#include <iostream> 
using namespace std;

int main(int argc, char const *argv[]){
	
	int a1,b1,a2,b2;
	int aTotal = 0, bTotal = 0;

	cin >> a1 >> b1;

	aTotal += a1;
	bTotal += b1;

	cin >> b2 >> a2;

	aTotal += a2;
	bTotal += b2;

	if(aTotal > bTotal){
		cout << "A wins";
	}else if(aTotal < bTotal){
		cout << "B wins";
	}else{

		if(a2 > b1){
			cout << "A wins";
		}else if(a1 < b2){
			cout << "B wins";
		}else{
			cout << "Extra time";
		}
		
	}


	return 0;
}