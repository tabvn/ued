#include <iostream>
using namespace std;

int h,m;

void ouputNumber(int n){
	cout << n;
}
int main(){

	cin >> h >> m;
	// 45 = (60 - 15) => -45 minues = -60 + 15 = - 1hour + 15
	if(h == 0){
		h = 24;
	}
	h = h-1;
	m = m + 15;
	if(m >= 60){
		h +=1; 
		m = m - 60;
	}
	if(h == 24){
		h = 0;
	}

	cout << h;
	cout << " ";
	ouputNumber(m);

	return 0;
}