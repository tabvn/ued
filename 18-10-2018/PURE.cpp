#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fi ("/Users/toan/ued/18-10-2018/PURE.INP");
ofstream fo ("/Users/toan/ued/18-10-2018/PURE.OUT");

vector<string> v;
vector<char> lastCharArr;
vector<char> currentCharArr;

int m;
string s;


void display(int len){

	cout << endl;
	cout << len << endl;


	for (int i = 0; i < len; ++i){
		cout << lastCharArr[i];
	}
	cout << endl;
	for (int i = 0; i < len; ++i){
		cout << currentCharArr[i];
	}
}

void find(int len){

	lastCharArr.clear();
	currentCharArr.clear();

	for (int i = 0; i < len; ++i){
		lastCharArr.push_back(s[i]);
	}



	int beginIndex = len -1;

	for (int i = beginIndex; i < s.size(); ++i){
		
		for (int j =0; j < len; ++j){
			beginIndex++;
			currentCharArr.push_back(s[beginIndex]);
		}


		display(len);
	}




}

int main(){

	fi >> m >> s;

	for (int i = 1; i <= m; ++i){
			find(i);
	}

	fi.close();
	fo.close();

	return 0;
}