#include <iostream> 
using namespace std;

int main(int argc, char const *argv[]){
	int n,p,q;

	cin >> n;

	int total =0;

	for (int i = 0; i < n; ++i){
		cin >> p >> q;
		if(q== 0 || p == q){
			continue;
		}

		if(p +2 <= q){

			total++;
		}

	}


	cout << total;
	return 0;
}