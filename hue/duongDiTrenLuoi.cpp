#include <iostream> 
using namespace std;

long long toHop (int n, int k )
{
    long res = 1;
    for ( int i = 1; i <= k ; i ++;)
    {
        res = res *n/i;
        n--;
    }
    return res;
}

int main(){
	int t,n;

	cin >> t;
	for (int i = 0; i < t; ++i){
		cin >> n;
		cout << toHop(n+n, n) << endl;
	}

	return 0;
}