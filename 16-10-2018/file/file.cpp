#include <iostream>
#include <fstream>

using namespace std;

FILE *f;

int main(){

	int x,y;

	ifstream fi ("/Users/toan/ued/16-10-2018/file/SUM.INP");

	fi >> x >> y;

	cout << "x:" << x << " y:" << y << endl;

	fi.close();

	return 0;
}