#include <iostream>
using namespace std;

int main(){
	
	int x,y,z;

	long long s, max=0;

	cin >> x >> y >> z;


	s = x + y * z;
	if(s > max){
		max = s;
	}	

	s = x + z * y;
	if(s > max){
		max = s;
	}	

	s = x * y + z;
	if(s > max){
		max = s;
	}	

	s = x * y + z;
	if(s > max){
		max = s;
	}	

	s = x * z + y;
	if(s > max){
		max = s;
	}	
	s = x + y + z;
	if(s > max){
		max = s;
	}	

	s = x * y * z;
	if(s > max){
		max = s;
	}	


	cout << max;

	return 0;
}