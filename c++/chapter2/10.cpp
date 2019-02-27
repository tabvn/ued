#include <iostream>
#include <iomanip>

using namespace std;

double solve(int pounds,int shillings, int pence){

	double total = pounds;
	double s = shillings + pence/12.0;	
	total += s/20;

	return total;

}
int main(){
	int pounds, shillings,pence;


	cout << "Enter pounds: ";
	cin >> pounds;
	cout << "Enter shillings: ";
	cin >> shillings;
	cout << "Enter pence: ";
	cin >> pence;
	cout << "Decimal pounds = £" << fixed<< setprecision(2) << solve(pounds, shillings, pence);
	return 0;
}