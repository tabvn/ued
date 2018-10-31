#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/*
/Users/toan/ued/16-10-2018/PALIN
*/

ifstream fi ("PALIN.INP");
ofstream fo ("PALIN.OUT");


bool doiXung(string s, long long length){

	if(length == 1){
		return true;
	}
	bool dx = false;
	long long i, j;
	i = 0;
	j = length - 1;
	while(s[i] == s[j]){
		if(i >= j){
			dx = true;
		}

		i++;
		j--;
	}

	return dx;
}
int main(){

	string s, xau;
	long long q, li, xauLength, stringLength;

	fi >> s;
	fi >> q;

	stringLength = s.size();

	for (int i = 0; i < q; ++i){

		fi >> li;
		
		bool isDoiXung = false;

		for(int i = 0; i < stringLength; ++i){	
			xau = "";
			xauLength = 0;

			for(int j = i; j < i+li; j++){
				xau+= s[j];
				xauLength++;
			}

			if(xauLength == li){
				// kiem tra tinh doi xung
				if(doiXung(xau, xauLength)){
					isDoiXung = true;
				}else{
					continue;
				}
			}

		}

		if(isDoiXung){
			fo << 1 << endl;
		}else{
			fo << 0 << endl;
		}

	}

	fi.close();
	fo.close();

	return 0;
}