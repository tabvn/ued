#include <iostream> 
using namespace std;

//Tìm số nguyên duong n nhỏ nhất sao cho 1 + 2 + 3 + ...... + n > 1000

long long sum(int n){
	return (n*(n+1))/2;

}
int main(){
	
	int n = 1000;
	int findNum = 0;

	for (int i = 0; i <= n ; ++i){
		if(sum(i) > n){
			findNum = i;
			break;
		}
	}
	cout << findNum;

	return 0;
}