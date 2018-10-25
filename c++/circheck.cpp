#include <iostream> 
#include <math.h>

using namespace std;


struct Point
{
	int x,y;
	
};

float len(Point a, Point b){

	return sqrt( pow((b.x - a.x), 1) - pow((b.y - a.y),2));
}
int main(){
	Point o, p;

	int x,y, r;

	cin >> x >> y;
	o.x = x;
	o.y = y;

	cin >> x >> y;
	p.x = x;
	p.y = y;
	cin >> r;

	float l = len(o,p);

	if(l == r){
			cout << "Tren";
	}else if(l < r){
		cout << "Trong";
	}
	else{
		cout << "Ngoai";
	}
	return 0;
}