#include <iostream> 
#include <vector>
using namespace std;

vector<int> v;

int main(){
	
	int n, c;

	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}
	if(n == 1){

		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; ++i){
		cin >> c;
		v.push_back(c);
	}

	int max = 0;
	int maxSoFar = 1;
	int start = 0;
	int end;

	int lastColor = v[0];

	for (int i = 1; i < v.size(); ++i){
	
		if(lastColor != v[i]){
			maxSoFar++;
			end = i;

			if(maxSoFar > max){
				max = maxSoFar;
			}
		}else{
			start = i;
			maxSoFar = 1;
		}

		lastColor = v[i];


	}
	cout << max;

	return 0;
}