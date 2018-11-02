#include <iostream> 
#include <vector>
#include <iomanip>
using namespace std;

/*
n!/k!(n-k)!
*/
vector<int> tu;
vector<int> mau;

int ucln(int a, int b){
	if(a == 1 || b == 1){
		return 1;
	}
	if(a %b == 0){
		return b;
	}
	if(b%a==0){
		return a;
	}

	while(a !=b){

		if(a > b){
			b = b;
			a = a-b;
		}
		if(b > a){
			a = a;
			b = b-a;
		}
	}

	return a;

}

double Cn(int k, int n){
	int uc = 1;
	
	// nhap tu
	for (int i = 1; i <= n; ++i){
		tu.push_back(i);
	}
	// mau
	for (int i = 1; i <= k; ++i){
		mau.push_back(i);
	}
	for (int i = 1; i <= (n-k); ++i){
		mau.push_back(i);
	}
	// lan luot lay tu chia mau
	for (int i = 0; i < tu.size(); ++i){

		if(tu[i] == 1){
			continue;
		}
		for (int j = 0; j < mau.size(); ++j){
			if(mau[j] == 1){
				continue;
			}
			// tim uoc chung roi gian uoc tu/mau
			uc = ucln(tu[i], mau[j]);
			if(uc > 1){
				tu[i] = tu[i]/uc;
				mau[j] = mau[j]/uc;
			}
		}
	}

	long long t1 = 1;
	long long t2 = 1;
	// tinh tich tu
	for (int i = 0; i < tu.size(); ++i){
		
		t1 *= tu[i];
	}

	// tinh tich mau
	for (int i = 0; i < mau.size(); ++i){
		t2 *= mau[i];
	}
	return double(t1/t2);
}
int main(){
	int k,n;
	cout << "Nhap k n: ";
	cin >> k >> n;

	double ketQua = Cn(k,n);
	long long kq = ketQua;
	if(kq == ketQua){
		cout << kq;
	}else{
		cout << fixed << setprecision(4) << ketQua;
	}
	
	return 0;
}