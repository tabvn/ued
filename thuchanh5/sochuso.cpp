#include <iostream>

using namespace std;

int numLenth(long int n){
	int length = 0;

	long int value = n;

	while(value > 0){
		length++;
		value /= 10;
	}

	return length;

}
int main(){

	long int n;
    
    cin >> n;

    cout << "So chu so: " << numLenth(n);
    
	return 0;
}