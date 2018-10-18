#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



/*

bool soChinhPhuong(long long n){

	float x = sqrt(n);
	return (x == (int)x);
}

void test(){	
	int k = 0;

	for (int i = 0; i < 4000000; ++i)
	{
		if((i-1)%3 == 0 && soChinhPhuong(i)){
			if(k == 2){
				cout << "num:" << i -1 << " ";
			}
			k++;

		}
		
		
	}
}
*/

struct Num{
	long long k;
	long long m;

};





vector<Num> v;

int main(){
	int numTest;
	Num n;
	long long k,m,result;


	cin >> numTest;

	for (int i = 0; i < numTest; ++i)
	{
		cin >> k >> m;

		n.k = k;
		n.m = m;

		v.push_back(n);

	}

	for (int i = 0; i < v.size(); ++i)
	{

		//(i+i/2+1)^2-1
		//i = k-1
		
		k = v[i].k;
		m = v[i].m;

		long long r = (k-1)+(k-1)/2 + 1;
		result = r*r - 1;
		cout << result%m << endl;
	}
	
	return 0;

}