#include <iostream>

using namespace std;

class Angle
{
public:
	int degrees;
	float minutes;
	char direction;

	Angle(int degrees, float minutes, char direction){

		this->degrees = degrees;
		this->minutes = minutes;
		this->direction = direction;
	}
	void print(){
	
		cout << this->degrees << '\xF8' << this->minutes << '\'' << " " << this->direction;

	}
	
};
int main(){
	
	Angle a(149, 34.8, 'W');

	a.print();

	return 0;
}