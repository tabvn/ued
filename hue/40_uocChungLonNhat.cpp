#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

long int ucln(long int a, long int b){

	if(a %b == 0){
		return b;
	}
	else if(b%a == 0){
		return a;
	}else{
		long int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;

	}
	 
}

void findUc(){
	if(v.size() == 2){
		cout << ucln(v[0], v[1]) * (int)v.size();
	}else{
		int uc = v[0];
		for (int i = 1; i < v.size(); ++i){
			uc = ucln(uc, v[i]);
		}
		cout << uc * (int)v.size();
	}
}


int main(){

	int t,n,a;
	cin >> t;

	for (int i = 0; i < t; ++i){
		cin >> n;
		v.clear();
		for (int j = 0; j < n; ++j){
			cin >> a;
			v.push_back(a);
		}
		findUc();
		cout << endl;
		
	}

	return 0;
}