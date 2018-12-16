#include <iostream> 
using namespace std;


int main(){
	int n,m,a;
	cin >> n >> m;

	int arr[n][m];

	for (int i = 0; i < n; ++i){
		
		for (int j = 0; j < m; ++j){
			cin >> a;
			arr[i][j] = a;

		}
	}

	long int s = 0;

	for (int i = 0; i < n; ++i){
		s = 0;
		for (int j = 0; j < m; ++j){
			s += arr[i][j];
		}

		cout << s << " ";
	}





	return 0;
}