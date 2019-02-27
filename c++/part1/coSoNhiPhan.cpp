#include <iostream> 
#include <vector>
using namespace std;

vector<int> v;

void heNhiPhan(int n){
	int num;
	while(n > 0){
		num = n%2;
		v.push_back(n%2);
		n /= 2;
	}

	for (int i = v.size()-1; i >= 0; --i){
		cout << v[i]<< " " << endl;
	}
}
int main(){
	int n;
	cin >> n;

	heNhiPhan(n);

	return 0;
}