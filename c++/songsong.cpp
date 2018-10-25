#include <iostream> 
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/c++/songsong.INP");

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

	Point a,b,c,d;
	


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

		

		}else{
			// D
			d.x = x;
			d.y = y;
		}
	}

	/*
	y = ax +b;
	y = a1x+b1
	2 đt cắt nhau khi: a khác a'
	2 đt // khi: a=a', b khác b'
	2 đt vuông góc khi: a = -1/a' 
	ta đi tìm nghiệm bằng cách thay toạ độ vào phương trình đường thằng y = ax+b; để tìm các giá trị a,b
	*/

	float a1 = heSoA(a,b);
	float b1 = heSoB(a,b);
	float a2 = heSoA(c,d);
	float b2 = heSoB(c,d);

	
	if(a1 == a2 && b1!=b2){
		cout << "TRUE";
	} 
	else{
		cout << "FALSE";
	}

	fi.close();

	return 0;
}