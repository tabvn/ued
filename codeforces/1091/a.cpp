#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

std::vector<int> v;
int main(int argc, char const *argv[]){
	
	int y,b,r;

	cin >> y >> b >> r;



	while(b-1 > y){
		b--;
	}


	while(r - 1 > b){
		
		r--;
		
	}

	if(r - 1 != b){
		b = r-1;
	}
	if(b-1 != y){
		y = b-1;
	}

	cout << y+b+r;
	return 0;
}