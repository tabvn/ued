#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

struct Num
{
	long int value;
	long long index;
	bool used;
	
};

Num num;

vector<Num> v;
vector<Num> result;

bool descSort(Num a, Num b){
	return a.value > b.value;
}

long long totalSum(){
	long long value  = 0;

	for (long long i = 0; i < v.size(); ++i){
		value += v[i].value;
	}

	return value;
}

void findSubArr(long long total){
	long long subTotal;

	for (long long i = 0; i < v.size(); ++i){
		subTotal = total - v[i].value;
		if(subTotal == v[i].value){
				continue;
		}
		for (long long j = 0; j < v.size(); ++j){
			if(j == i){
				continue;
			}
			if(subTotal - v[j].value > v[i].value){
				break;
			}
			if(v[j].used == false && subTotal - v[j].value == v[i].value){
				// bo vi tri nay ok
				v[j].used = true;
				result.push_back(v[j]);

			}
		}
	}

	cout << result.size() << endl;
	for (long long i = 0; i < result.size(); ++i){
		cout << (result[i].index +1) << " ";
	}
}

int main(){
	long long n;
	long int a;

	cin >> n;

	for (long long i = 0; i < n; ++i){

		cin >> a;
		num.value = a;
		num.index = i;
		num.used = false;
		v.push_back(num);

	}
	sort(v.begin(), v.end(), descSort);
	findSubArr(totalSum());

	return 0;
}