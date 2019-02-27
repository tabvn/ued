#include <iostream>
using namespace std;
	
double solve(double money, int year, double rate){	

	for (int i = 0; i < year; ++i){
		money += (money * rate / 100);
	}

	return money;

}
int main(){

	double money, rate, invest;
	int year;


	cout << "Enter initial amount: ";
	cin >> money;
	cout << "Enter number of years: ";
	cin >> year;
	cout << "Enter interest rate (percent per year): ";
	cin >> rate;

	invest = solve(money, year, rate);
	cout << "At the end of "<< year<<" years, you will have "<<invest<<" dollars.";

	return 0;
}