#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("NUMSEQ.INP");
ofstream fo ("NUMSEQ.OUT");

vector<int> lastV;
int num;

bool checkIsExist(int n){

	bool isExist = false;
	for (int i = 0; i < lastV.size(); ++i){
		if(n == lastV[i]){
			isExist = true;
			break;
		}
	}
	return isExist;
}

bool checkNum(int n){

	vector<int> vi;
	int c;

	while(n > 0){
		c = n%10;
		if(checkIsExist(c)){
			return false;
		}

		vi.push_back(c);

		n /= 10;

	}

	lastV.clear();
	for (int i = 0; i < vi.size(); ++i){
		lastV.push_back(vi[i]);
	}
	vi.clear();
	return true;

}

int searchNum(int n ){
	int inc = 0;
	int ai = 0;
	while(inc <= n){
		if(checkNum(ai)){
			num = ai;
			inc++;
		}

		ai++;
	}

	return num;
}

int main(){
	int n;
	fi >> n;
	fo << searchNum(n);

	fi.close();
	fo.close();

	return 0;
}