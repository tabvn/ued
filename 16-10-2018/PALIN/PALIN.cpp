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

vector <long long> v;


bool doiXung(string s, long long length){

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

	for (int i = 0; i < q; ++i){

		fi >> li;
		v.push_back(li);	

	}

	stringLength = s.size();
	


	for(int inc = 0; inc < v.size(); inc++){

		bool isDoiXung = false;

		for(int i = 0; i < stringLength; ++i){	
			
			li = v[inc];

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