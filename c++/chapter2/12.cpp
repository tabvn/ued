#include <iostream>
using namespace std;

void solve(double pounds){
	int shillings,pence;
	
	int p = (int) pounds;
	double s = pounds - p;
	double shi= s*20;
	shillings = (int) shi;
	pence = (shi - shillings) * 12;
	cout << p << "." << shillings<< "." << pence << ".";

}

int main(){
	double pounds;

	cout << "Enter decimal pounds: ";
	cin >> pounds;
	cout << "quivalent in old notation = £";
	solve(pounds);

	return 0;
}