#include <iostream> 
using namespace std;


long int demSoChan(long int n){
	long long s = 0;

	for (long long i = n; i <= 2*n; ++i){
		
		if( i%2 == 0){
			s++;
		}
	}

	/*
	if(n %2 != 0){
		s = (n/2) + 1;
	}else{
		s = n/2;
	}
	*/

	return s;

}
long int howManyStringToCut(long int n){


	if(n == 0){
		return 0;
	}

	long int total = 0;

	long int soChan = demSoChan(n);

	/*for (long long i = n/3; i <= n; ++i){
		if(i % 2 != 0 && ((3*i) + 1) >= n ){
			total ++;
		}
	}
	*/

	long int startNum = n/3;
	if(startNum*3+1 < n){
		startNum++;
	}
	
	//total = ((n - startNum)/2) + 1;

	for (long int  i = startNum; i <= n; ++i){
		if(i %2 != 0){
			total ++;
		}
	}

	if(n %2 == 0){
		total --;
	}

	return total + soChan;

}
int main(){
	
	
	long int n;

	cin >> n;

	cout << howManyStringToCut(n);

	return 0;
}