#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> v;

int main(int argc, char const *argv[]){
	int n, num;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> num;
		v.push_back(num);
	}
	

	return 0;
}