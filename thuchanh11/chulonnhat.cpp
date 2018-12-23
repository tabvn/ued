#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> digits;

bool descSort(int a, int b){
	return a > b;
}

int solve(long int n){

	if(n <= 9){
		return n;
	}

	while(n > 0){
		digits.push_back(n%10);
		n/= 10;
	}

	if(digits.size() > 0){
		sort(digits.begin(), digits.end(), descSort);
		return digits[0];
	}

	return 0;

}
int main(){
	long int n;
	cin >> n;
	int maxNum = solve(n);
	cout << "Chu so lon nhat: " << maxNum;
	return 0;
}