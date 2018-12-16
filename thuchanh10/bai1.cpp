#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Congnhan
{
	char ten[256];
	int namsinh;
	int gio_lam;
	
};
vector<Congnhan> vArr;
Congnhan cn;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
			fflush(stdin); // cần khi dùng hàm gets
			gets(cn.ten);
			cin >> cn.namsinh >> cn.gio_lam;
			vArr.push_back(cn);
	}

	for (int i = 0; i < vArr.size(); ++i){
		cn = vArr[i];
		if(cn.gio_lam >= 40){
			cout << cn.ten << endl;
		}
	}
	return 0;
}