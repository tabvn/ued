#include <iostream> 
#include <math.h>

using namespace std;

int main(){
	
	int q,x,y,n;

	cin >> q;

	long long product;
	long long sum;
	double can;

	long long s;
	long long nn;


	for (int i = 0; i < q; ++i){
		cin >> n;
		nn = n*n;
		x = 1;
		y = nn;


		while(true){	

			s = (x+y)+(x*y);
			//cout << "s:" <<s << "x:"<<x << "y:"<<y << endl;
			if(s == nn){
				break;
			}

			x++;
			if(x == y){
				x = 1;
				y--;
			}

		}

		cout << x << y << endl;

	}

	
	return 0;
}