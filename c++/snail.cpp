#include <iostream> 
using namespace std;

int snail(long int a, long int b, long int v){

	int d = 0;
	long int current = 0;

	while(current <=v){

		current += a;
		current -= b;
		
		if(current == v){
			return d;
		}

		d++;

		
	}

	return d;
}

int main(){
	
	long int a,b,v;

	cin >> a >> b >> v;
	cout << snail(a, b, v);


	return 0;
}