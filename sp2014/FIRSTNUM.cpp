#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fi("FIRSTNUM.INP"); // file input
ofstream fo("FIRSTNUM.OUT"); // file output
char digitToChar(int num){
	switch(num){
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	default:
		return '0';
	}
	
}

string numToString(int num){
	string str = "";

	int digit;
	while(num > 0){
		digit = num %10;
		str += digitToChar(digit);
		num /= 10;
	}

	// tien hanh dao nguoc string
	reverse(str.begin(), str.end());

	return str;
}

void solve(int n){
	

	string s;
	string str;

	for (int i = 1; i <= n; ++i){
		str = numToString(i);

		for (int j = 0; j < str.size() ; ++j){
			s += str[j];
		}
	}
	string findString = numToString(n);
	long int findIndex = -1;

	for (int i = 0; i < s.size(); ++i){

		if(s[i] == findString[0]){
			bool isOk = true;
			for (int j = 0; j < findString.size(); ++j){
				if(s[i + j] != findString[j]){
					isOk = false;
					break;
				}
			}

			if(isOk == true){
				findIndex = i;
				break;
			}
		}	
	}

	cout << (findIndex + 1);

}



int main(){

	int n;

	fi >> n;

	solve(n);

	fi.close();
	fo.close();



	return 0;
}