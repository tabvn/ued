#include <iostream> 
#include <fstream>

using namespace std;

ifstream fi ("/Users/toan/ued/RATEEQUA.INP");
ofstream fo ("/Users/toan/ued/RATEEQUA.OUT");


int main(){
	long long a,n;

	fi >> a >> n;

	cout << a << n;
	return 0;
}