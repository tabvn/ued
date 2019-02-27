#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> v;

bool mySort(int a, int b){
	return a < b;
}
int main(int argc, char const *argv[]){
	
	
	int n,a;

	cin >> n;

	long long s = 0;
	for (int i = 0; i < n; ++i){
		cin >> a;
		s+= a;
		v.push_back(a);
	}

	if(s == 0 || s%360 == 0){

		cout << "YES";

		return 0;
	}

	sort(v.begin(), v.end(), mySort);

	s = v[0];

	for (int i = 1; i < v.size(); ++i){
		if(s == 360){
			s = 0;
		}
		if(s > 360){
			s = s%360;
		}

		if(s- v[i] == 0 || s-v[i] %360 == 0){
			s-= v[i];
		}else{
			s += v[i];
		}

	
	}

	if(s == 0 || s%360 == 0){

		cout << "YES";
	}else{

		cout << "NO";
	}

	return 0;
}