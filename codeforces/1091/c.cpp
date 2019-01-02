#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

std::vector<long long> v;

bool ascSort(long long a, long long b){
	return a < b;
}
int main(int argc, char const *argv[]){
	
	long int n;

	cin >> n;

	long long s = ((n+1) *n) /2;

	long int max;

	if(n %2 == 0){
		max = n/2;
	}else{
		max = n/2 +1;
	}

	long long value = 0;
	long int p;

	v.push_back(s);
	v.push_back(1);

	for (long int i = 2; i <= max; ++i){
		

		p = 1+i;
		value = p;
		for (long int	 j = 1; j < n/i - 1; ++j){

			p += i;
			value += p;
			

		}

		value += 1;
		v.push_back(value);

		
	}

	sort(v.begin(), v.end(), ascSort);

	for (long int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}

	return 0;
}