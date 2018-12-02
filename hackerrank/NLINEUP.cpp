#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

struct Num
{
	int value;
	int index;
	
};

Num num;
vector<Num> v;
vector<int> arr;

bool descSort(Num a, Num b){
	return a.value > b.value;
}

int one =0;
int two = 0;
int three = 0;

int main(){
	
	int n,a;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a;
		num.index =i;
		num.value = a;

		v.push_back(num);
		arr.push_back(a);
	}

	sort(v.begin(), v.end(), descSort);

	Num lastNumTwo;
	Num lastOne;

	lastNumTwo.index = -1;
	lastNumTwo.value=  -1;

	lastOne.index = -1;
	lastOne.value = -1;


	int current = 3;
	for (int i = 0; i < v.size(); ++i){
		if(v[i].value != current){
			current--;
		}
		if(current == 3){
			if(v[0].index == 0 && v[i].index > 0 && v[i-1].index+1 == v[i].index){
				continue;
			}
			if(v[i].index != 0){
				three++;
			}
			
		}
		else if(current == 2){
			if(lastNumTwo.index != -1 && lastNumTwo.index+1 == v[i].index){
				// day so 2 lien tiep
				continue;
			}

			lastNumTwo = v[i];

			if(v[i+1].index == v[i].index +1){
				continue;
			}
			two ++;
		}else{
			one++;
		}

	}

	bool isStillOne = true;
	for (int i = arr.size() -1; i >=0; --i){
		if(arr[i] != 1){
			isStillOne = false;
			break;
		}

		if(isStillOne){
			one --;
		}
	}

if(one == 0){
	bool isStillTwo = true;
	for (int i = arr.size() -1; i >=0; --i){
		if(arr[i] != 2){
			isStillTwo = false;
			break;
		}
		if(isStillTwo){
			two --;
		}
	}
}
	


	//cout << "three:"<< three << " two:" << two << " one:" << one << endl;
	if(one == 0){
			if(three < two){
				cout << three;
			}
	}
	else if(three == 0){
		if(two >> one){
			cout << one;
		}else{
			cout << two;
		}
	}
	else if(two == 0){
		if(three > one){
			cout << one;
		}else{

			cout << three;
		}
	}
	else{
		
		cout << three + one + two;
		
	}
	

	return 0;
}