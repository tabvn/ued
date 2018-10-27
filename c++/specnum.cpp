#include <iostream> 
using namespace std;

bool isSpecNum(int n){
	int s1 = 0;
	int s2 = 0;
	int num;
	while(n > 0){
		num = n%10;
		if(num %2 == 0){
			s1+= num;
		}else{
			s2+= num;
		}

		n /= 10;

	}

	return s1 == s2;


}
int main(){
	
	int a,b;
	cin >> a >> b;

	int total = 0;
	for (int i = a; i <= b; ++i){
		if(isSpecNum(i)){
			total ++;
		}
	}

	cout << total;

	return 0;
}