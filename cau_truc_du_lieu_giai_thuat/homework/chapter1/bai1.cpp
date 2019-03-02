#include <iostream>

using namespace std;


int ucln(int a, int b){

	if(a == b){
		return a;
	}

	if(a > b){
		return ucln(a - b, b);
	}
	
	return ucln(a, b-a);

}

int main(){
	
	int a, b;

	cout << "Nhap A: ";
	cin >> a;

	cout << "Nhap B: ";

	cin >> b;

	cout << ucln(a,b);
	return 0;
}