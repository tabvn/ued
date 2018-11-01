#include <iostream> 
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ifstream fi ("PARK.INP");
ofstream fo ("PARK.OUT");

struct Xe{
	string bienSo;
	int total;
};


vector<Xe> v;

int findIndex(string s){

	for (int i = 0; i < v.size(); ++i){
			if(v[i].bienSo == s){
				return i;
			}
	}

	return -1;
}
void guiXe(string s){

	Xe x;
	int fIndex = findIndex(s);
	if( fIndex == -1){
		// them xe moi
		x.bienSo = s;
		x.total = 1;
		v.push_back(x);

	}else{
		v[fIndex].total += 1;
	}
	
}

long long calculate(int n){

	if(n <= 5){
		return 100;
	}
	return 100 + (n-5);
}
long long tinhTien(Xe xe){
	int p = xe.total;
	return calculate(p);
}

int main(){

	int k;
	string s;

	fi >> k;

	long long money = 0;

	for (int i = 0; i < k; ++i){
		fi >> s;
		guiXe(s);
	}

	for (int i = 0; i < v.size(); ++i){
		money += tinhTien(v[i]);
		
	}

	fo << money;

	fo.close();
	fi.close();

}