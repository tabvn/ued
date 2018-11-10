#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

vector<long int> s;
vector<long int> p;

long int a[200000000];
long long total = 0;
const int isDebug = false;

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

bool tatCaBangMot(vector<long int> b){
	for (int i = 0; i < b.size(); ++i){
		if(b[i] != 1){
			return false;
		}
	}	
	return true;
}

bool chiaHet(vector<long int> a, vector<long int> b){

	long int uc;

	bool ucBangMot = true;
	for (int i = 0; i < a.size(); ++i){
		for (int j = 0; j < b.size(); ++j){
			uc = ucln(a[i], b[j]);
			if(uc > 1){
				a[i] = a[i]/uc;
				b[j] = b[j]/uc;
				ucBangMot = false;
			}
		}
	}

	
	if(tatCaBangMot(b)){
	
		return true;

	}else if(tatCaBangMot(a) || ucBangMot == true){
		// ko chia het
		return false;
	}else{

		return false;
		//return chiaHet(a, b);
	}

	return false;
}



void display(int k){
	vector<long int> v;
	for (int i =1; i <= k; ++i){
		v.push_back(s[a[i]-1]);		
	}

	if(chiaHet(v, p)){
		
		total++;
	}
	
}
void lietke(int i, int k){

	int n = (int) s.size();

	for (int j = a[i-1] + 1; j <= n-k+i; ++j){
		a[i] = j;
		if(i == k){
			display(k);
		}else{
			lietke(i+1, k);
		}
	}
}

bool descSort(long int a, long int b){
	return a > b;
}

int main(){
/*
3
4 5 6
2
2 3
*/
	int n,m;
	long int ai;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> ai;
		s.push_back(ai);	
	}

	cin >> m;
	for (int i = 0; i < m; ++i){
		cin >> ai;
		p.push_back(ai);
	}

	sort(s.begin(), s.end(), descSort);
	sort(p.begin(), p.end(), descSort);

	a[0] = 0;
	for (int i = 1; i <= s.size(); ++i){
		lietke(1, i);
	}
	
	cout << total%1000000007;

	return 0;
}