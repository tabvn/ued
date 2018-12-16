#include <iostream> 
#include <vector>
using namespace std;

struct Point
{
	int x,y,z;
};
Point p;
vector<Point> v;

bool solve(){

	long xSum = 0, ySum = 0, zSum = 0;
	for (int i = 0; i < v.size(); ++i){
		xSum+= v[i].x;
		ySum += v[i].y;
		zSum += v[i].z;
	}
	return xSum == 0 && ySum ==0 && zSum ==0;
}
int main(){
	int n;
	cin >>n;

	for (int i = 0; i < n; ++i){
		cin >> p.x >> p.y >> p.z;
		v.push_back(p);
	}

	bool yes = solve();
	if(yes){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}