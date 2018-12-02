#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

// ruou , ten doc meo het mieng :D 
struct R{
	int index;
	int value; // nong do con 
	R(int i, int v){
		this->index = i;
		this->value = v;
	}

};

vector<R*> v;
long long sum = 0;
bool allZero = true;

bool descSort(R *a, R *b){
	return a->value > b->value;
}

void doTheJob(int q){
	

	if(q == 0 && allZero){
		cout << "NO"<< endl;
	}else{
		sort(v.begin(), v.end(), descSort);

		int total = 0;
		int max = 999999999;
		bool isOk = false;

		for (int i = 0; i < v.size(); ++i){
			if(v[i]->value == q){
				total = 1;
				break;
			}

			if(v[i]->value < q){
				break;
			}

			for (int j = 0; j < v.size(); ++j){
				if(i == j){
					continue;
				}
				if((v[i]->value - q) % v[j]->value == 0 && (v[i]->value - q )/(v[j]->value) + 1 < max){
					isOk = true;
					max = (v[i]->value -q) / (v[j]->value) + 1;
				}


			}

		}
		total = max;
		if(!isOk){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
			cout << total;
		}


	}
	
}

void clearMem(){
	for (int i = 0; i < v.size(); ++i){
		delete v[i];
	}
}
int main(){
	
	int n,q,a;

	cin >> n >> q;

	for (int i = 0; i < n; ++i){
		cin >> a;
		sum+= a;
		if(a > 0){
			allZero = false;
		}

		R *r = new R(i, a);
		v.push_back(r);

	}

	doTheJob(q);
	clearMem();

	return 0;
}