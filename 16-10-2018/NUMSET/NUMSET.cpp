#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct B{
	string s;
	int size;
	vector<string> v;
};

/*
/Users/toan/ued/16-10-2018/NUMSET
*/

ifstream fi ("NUMSET.INP");
ofstream fo ("NUMSET.OUT");


vector<B> vb;
B b;

string timString(string s, int x){
	string result = "";
	string checkS = "";

	for (int i = 0; i < s.size(); ++i){
		if(i != x){
			result += s[i];
		}
	}

	if(result[0] == '0'){
		return "";
	}

	// kiem tra va xoa cac day trung nhau
	for (int i = 0; i < vb.size(); ++i){
		checkS = vb[i].s;
		if(checkS == result){
			return "";
		}
	}

	return result;
}

bool xoaSo(int lengh){

	string findS;
	string tmp = "";

	if(lengh == 1){

		return true;
	}else{
		xoaSo(lengh -1);
	}
	for (int i = 0; i < vb.size(); ++i){
		
		tmp = vb[i].s;

		for(int j = 0; j < tmp.size(); j++){
			findS = timString(vb[i].s, j);
			if(findS != ""){
				b.s = findS;
				b.size = lengh;
				vb.push_back(b);
			}
		}
	}



	return true;
}

int charToInt(char c){
	switch(c){

		case '0':

			return 0;

		case '1':
		
			return 1;

		case '2':
		
			return 2;
		case '3':
		
			return 3;

		case '4':
		
			return 4;
		case '5':

			return 5;	

		case '6':

			return 6;
		case '7':
		
			return 7;
		case '8':
		
			return 8;

		case '9':
		
			return 9;

		default:

			return 0;
	}
}

bool stringChiaHetThree(string str, int size){

	
	int tong = 0;
	for (int i = 0; i < size; ++i){
		tong += charToInt(str[i]);
		
	}

	//cout << "kt: "<< str << " size: "<<size  << " tong" << tong << " chiahet" << (tong % 3 == 0)<< endl;

	if(tong % 3 == 0){
		return true;
	}
	return false;
	
}
int main(){

	string s;
	//1005
	fi >> s;

	int stringLength = s.size();
	string findS = "";

	for (int i = 0; i < stringLength; ++i){
		findS = timString(s, i);
		if(findS != ""){
			b.s = findS;
			b.size = stringLength - 1;
			vb.push_back(b);

		}
	}

	xoaSo(stringLength -1);
	int total = 0;
	// them luon cai string goc vao
	b.s = s;
	b.size = stringLength;

	vb.push_back(b);
	for (int i = 0; i < vb.size(); ++i){
		// kiem tra tong cac int chia het cho 3
		if(stringChiaHetThree(vb[i].s, vb[i].size)){
			total ++;
		}
	
	}

	// ouput
	fo << total;

	fi.close();
	fo.close();

	return 0;
}