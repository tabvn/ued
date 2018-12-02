#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

int question(long double x,long double y)
{
	cout << "Q " << setprecision(10) << fixed << x << ' ' << y << endl;
	int res;
	cin >> res;
	return res;
}

void answer(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
{
	cout << "A " << setprecision(10) << fixed << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}
int main() 
{
	question(0,0);
	question(0,2);
	question(sqrt(3),1);
	answer(0,0,0,2,sqrt(3),1);
	return 0;
}
