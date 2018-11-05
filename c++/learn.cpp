#include <iostream> 
#include <vector>
using namespace std;


struct Point
{
	int x, y;
	Point(int _x, int _y){
		x = _x;
		y = _y;
	};
};


std::vector<Point*> v;
void addPoint(int x, int y){

	Point *p = new Point(x, y);
	
	v.push_back(p);

	
}

int main(){
	
	for (int i = 0; i < 10; ++i){
		addPoint(i, 0);
	}
	
	for (int i = 0; i < v.size(); ++i){
		cout << v[i]->x << ":" << v[i]->y << endl;
	}


	return 0;
}