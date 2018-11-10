#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct LastCheck
{
	int len;
	bool isDx;

	LastCheck(){
		this->len = 0;
		this->isDx = false;
	}
};

ifstream fi ("PALIN.INP");
ofstream fo ("PALIN.OUT");

LastCheck lastCheck;

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
			break; // updated just now
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

	lastCheck.isDx = false;
	lastCheck.len = 0;

	for (int i = 0; i < q; ++i){

		fi >> li;
		
		bool isDoiXung = false;

		if(li == 1){
			isDoiXung = true;
		}
		else if(lastCheck.isDx == false && lastCheck.len >= li){
			isDoiXung = false;
		}
		else if(li > stringLength){
			isDoiXung = false;
		}
		else{
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
						break;
					}else{
						continue;
					}
				}
			}

		}

		if(isDoiXung){
			fo << 1 << endl;

		}else{
			if(li > lastCheck.len){
				lastCheck.isDx = false;
				lastCheck.len = li;
			}
			
			fo << 0 << endl;
		}

	}

	fi.close();
	fo.close();

	return 0;
}