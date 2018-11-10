#include <iostream> 
#include <vector>
#include <cstdlib>

using namespace std;

vector<long long> v;
double a[200];

double total = 0;

void display(int k){

	long long x1,x2;

	x1 = v[a[1]-1];
	x2 = v[a[2]-1];

	total += double((x1 + x2)/2);
	/*
	cout << v[a[1]-1] << " + "<< v[a[2]-1] << "=" << double((x1) + (x2))/2;
	cout << endl;
	*/
	
}
void lietke(int i, int k){

	int n = (int) v.size();

	for (int j = a[i-1] + 1; j <= n-k+i; ++j){
		a[i] = j;
		if(i == k){
			display(k);
		}else{
			lietke(i+1, k);
		}
	}
}


int main(){
	long long n;
	long long x;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		
		v.push_back(x);
	}


	a[0] = 0;
	lietke(1, 2);

	cout << total;
	return 0;
}