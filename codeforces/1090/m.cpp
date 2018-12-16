#include <iostream> 
#include <vector>
using namespace std;

vector<int> v;

int main(int argc, char const *argv[]){
	int n,k;
	int a;

	cin >> n >> k;

	if(k == 1){
		cout << 1;
		return 0;
	}
	if(n == 1){
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}


	int maxSofar = 0;
	int startSofar = 0;
	int endSofar = -1;

	int max = 0;
	int start = 0;
	int end = -1;


	int num = v[0];
	for (int i = 1; i < v.size(); ++i){
		if(v[i] == num){
			startSofar = i;
			endSofar = i;
			maxSofar = 0;
		}
		if(v[i] != num){
				endSofar = i;
				maxSofar ++;
		}

		if(maxSofar > max){
			start = startSofar;
			end = endSofar;

			 max = maxSofar;
		}
		num = v[i];
	}
	//cout << "From:"<< start << " end:" << end << endl;

	cout << (end - start +1);
	return 0;
}