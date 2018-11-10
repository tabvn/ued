#include <iostream> 
#include <limits>

using namespace std;

#define NIL -1
#define MAX 250

long long v[MAX];

void initialize(){
	for (int i = 0; i < MAX; ++i){
		v[i] = NIL;
	}
}

long long fib(int n){
	if(v[n]== NIL){
		if(n <= 1){
			v[n] = n;
		}else{
			v[n] = fib(n -1 ) + fib(n-2);
		}
	}
	
	return v[n];
}

int main(){
	long int n;
	string s;
	initialize();
	while(true){
		
			cout << "Enter number: ";
			cin >> n;
			cout << fib(n)<<endl;
		
	}
	
	return 0;
}