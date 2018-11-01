#include <iostream> 
#include <iomanip>

using namespace std;

struct Point
{
	double x,y;
};

Point A;
Point B;
Point C;

int main(){

	double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	// Gán toạ độ điểm A
	A.x = x1;
	A.y = y1;

	// gán toạ độ điểm B

	B.x = x2;
	B.y = y2;

	C.x = (B.x+ A.x)/2;
	C.y = (B.y + C.y)/2;

	cout << fixed<< setprecision(2) << C.x << " " << C.y;
	

	return 0;
}