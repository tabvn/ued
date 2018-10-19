#include <iostream>

using namespace std;
#define SIZE 16
#define ST cout << endl; for (int i = 0; i < SIZE; ++i){cout << (char)42;} cout << endl;
#define CR for (int i = 0; i < SIZE; ++i){cout << c[i];}
char c[16] = {67,72,85,67, 32, 77,85,78,71, 32, 50,48,45,49,48,33};

int main(){
	ST;
	CR;
	ST;
	cout << endl;
	return 0;
}