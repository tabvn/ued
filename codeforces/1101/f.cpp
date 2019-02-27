#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<long int> cities;
vector<long int> trucks;



bool ascSort(long int a, long int b){
	return a < b;
}



long long findNum(int from, int to, long int f, long int c){

	vector<long int> seg;

	long int last = -1;

	for (int i = from -1; i <= to - 1; ++i){
		if(last != -1){
			seg.push_back(cities[i] - last);

		}

		last = cities[i];
	}

	long long total = 0;




	return total;



}


int main(){
	int n,m;
	long int a;

	cin >> n >> m;

	
	for (int i = 0; i < n; ++i){
		cin >> a;
	
		
	
		cities.push_back(a);
	}	




	int from, to; 
	long int f,c;

	long long result = -1;
	long long current;

	for (int i = 0; i < m; ++i){
		cin >> from >> to  >> f >> c;

		current = findNum(from, to, f,c);
		if(current > result){
			result = current;
		}
	}

	cout << result;

	return 0;
}