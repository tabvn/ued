#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
	int n;
	cin >> n;

	long long s = 0;

	for (int i = 0; i <= n; ++i){
		if(i%2 == 0){
			s+= i;
		}
	}
	cout << s;
	
	return 0;
}