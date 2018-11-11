#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

bool ascSort(long long a, long long b){
	return a < b;
}

long long ucln(long long a, long long b){

	if(a %b == 0){
		return b;
	}
	else if(b%a == 0){
		return a;
	}else{
		long int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;

	}

}

int main(){
	int n;
	long long a;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), ascSort);

	int maxLength = 1;
	int length = 1;

	long long lastNum = v[0];

	for (int i = 1; i < v.size(); ++i){
		if(ucln(v[i], lastNum) == 1){
			length ++;
			maxLength++;
		}else{
			if(length > maxLength){
				maxLength = length;
			}
			length = 1;
		}
		lastNum = v[i];
	}
	
	/*
	for (int i = 0; i < v.size(); ++i){
		length = 1;
		for (int j = i+1; j < v.size(); ++j){
			if(ucln(v[i], v[j]) == 1){
				// 
				length++;
			}
		}
		if(length > maxLength){
			maxLength = length;
		}
	}*/


	cout << maxLength;

	return 0;
}