#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int LEN = 5;
int arr[LEN] = {1,2,3,2,1};

bool check(int left, int right){

	if(right == 0){
		return true;
	}
	if(right <= left || arr[left] != arr[right]){
		return arr[left] == arr[right];
	}

	return check(left +1, right -1);

}

int main(){

	cout << check(0, LEN-1);
	return 0;
}