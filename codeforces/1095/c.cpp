#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Num
{
	int p;
	long int value;
};

vector<Num> v;

int getDeg(int n){

	int x = 0;

	while(true){

		if(pow(2, x) == n){
			break;
		}
		x++;
	}

	return x;
}

void convertNum(long int n){
	long long p;
	int x = 0;

	int left = 0;

	while(true){
		p = pow(2,x);
		if(p == n){
			break;
		}
		if(p > n){
			x--;
			left = n - pow(2,x);
			break;
		}
	
		x++;
	}

	Num num;

	num.p = x;
	num.value = pow(2,x);
	v.push_back(num);


	if(left == 1){
		num.p = 0;
		num.value = left;
		v.push_back(num);
	}
	if(left == 2){
		num.p = 1;
		num.value = left;
		v.push_back(num);
	}
	if(left > 2){
		convertNum(left);
	}

	
	

}

bool ascSort(Num a, Num b){
	return a.value < b.value;
}

bool allIsTwo(){

	for (int i = 0; i < v.size(); ++i){
		if(v[i].value > 2){
			return false;
		}
	}

	return true;
}

int main(){
	
	long int n ,k;
	cin >> n >> k;
	convertNum(n);

	if(v.size() > k){
		cout << "NO";
		return 0;
	}



	

	if(v.size() == k){
		sort(v.begin(), v.end(), ascSort);
		cout << "YES" << endl;
		for (int i = 0; i < v.size(); ++i){
			cout << v[i].value << " ";
	
		}

		return 0;
	}

	Num nNum;
	
	for (int i = 0; i < v.size(); ++i){
		if(v.size() == k){
				break;
		}
		if(v[i].value == 1 || v[i].value %2 != 0){
			continue;
		}

		while(v[i].value >= 2){
			
			nNum.value = v[i].value/2;
			nNum.p = 1;

			v.push_back(nNum);

			v[i].value /= 2;

			if(v.size() == k){
				break;
			}

		}
	}
	
	
	if(v.size() == k){
		sort(v.begin(), v.end(), ascSort);
		cout << "YES" << endl;
		for (int i = 0; i < v.size(); ++i){
			cout << v[i].value << " ";

		}
	}else{
		cout << "NO";
	}
	




	

	return 0;
}