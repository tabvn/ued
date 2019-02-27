#include <iostream> 
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/c++/threepnt.INP");

struct Point
{
	int x,y;
	
};

float heSoA(Point a, Point b){

	return (a.y - b.y)/(a.x - b.x); 
}

float heSoB(Point a, Point b){

	float hsA = heSoA(a,b);
	return a.y - hsA*a.x;
}

int main(){
	
	int x,y;

	Point a,b,c;
	


	for (int i = 0; i < 4; ++i){
		fi >> x >> y;

		if(i == 0){
			// A
			a.x = x;
			a.y = y;
		}
		else if(i == 1){
			// B
			b.x = x;
			b.y = y;
		}
		else if(i == 2){
			// C
			c.x = x;
			c.y = y;

		

		}
	}

	float a1 = heSoA(a,b);
	float b1 = heSoB(a,b);


	//cout << "a:" << a1 << " b:" << b1 << " cx:" << c.x << " cy:" << c.y ; 
	// ta co phuong trinh duong thang, gio thay the diem c vao xem co nghiem ko
	// y = ax +b
	if(c.y == a1*c.x + b1){
		// diem c nam tren duong thang
		cout << "TRUE";
	}else{

		cout << "FALSE";

	}

	fi.close();

	return 0;
}