#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	int x,y;
};

int abs(int x){
	if(x < 0){
		return 0 - x;
	}else{

		return x;
	}
}

Point A;
Point B;
Point C;

int lenOfTwoPoints(Point A, Point B){
  return abs(sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)));
}

int main(){

	int x, y;



	cin >> x;
	cin >> y;
	A.x = x;
	A.y = y;

	cin >> x;
	cin >> y;
	B.x = x;
	B.y = y;

	cin >> x;
	cin >> y;
	C.x = x;
	C.y = y;

	int AB,AC,BC, maxLength;

	AB = lenOfTwoPoints(A,B);
	AC = lenOfTwoPoints(A,C);
	BC = lenOfTwoPoints(B,C);



	if(AB > AC){
		// canh huyen la AB;

		if( AB *AB == AC*AC + BC*BC){
			// la tam giac vuong
			cout << "Vuong";
		}

	}else if(BC > AC){
		// canh huyen la BC
		if( BC *BC == AC*AC + AB*AB){
			// la tam giac vuong 
			cout << "Vuong";
		}

	}else{

		// canh huyen la AC
		if( AC *AC == AB*AB + BC*BC){
			// la tam giac vuong tai B
			cout << "Vuong";
		}else{

			cout << "Goc tu";
		}

	}



	return 0;
}