#include <iostream>
#include <vector>

using namespace std;


long long n;

vector<long long> v;


/*
long long fn(long long n){
	long long sum;

	if(n == 1 || n == 2){
		return 1;
	}else{
		sum = fn(n -1) + fn(n-2);
	}

	return sum;

}*/



long long fn(long long n){

	long long value = 0;

	if(n == 4){
		return 3 + 2;
	}
	
	int inc = 2;
	for (int i = 3; i <= n; ++i){
			v.push_back((v[inc-1] %13 + v[inc-2] % 13) %13);
			inc ++;
	}

	for (int i = 0; i < v.size(); ++i){
		value += v[i];
	}

	return value;
}


int main(){

	cin >> n;

	long long total = 0;

	v.push_back(1);
	v.push_back(1);

	total = fn(n);
	cout << total % 13;

	return 0;

}