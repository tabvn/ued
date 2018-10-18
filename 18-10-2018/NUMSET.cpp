#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
ifstream fi ("/Users/toan/ued/18-10-2018/NUMSET.INP");
ofstream fo ("/Users/toan/ued/18-10-2018//NUMSET.OUT");
*/


ifstream fi ("NUMSET.INP");
ofstream fo ("NUMSET.OUT");

string s;
vector<string> v;
long int total = 0;

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

bool stringChiaHetThree(string str){

	
	int tong = 0;
	for (int i = 0; i < str.size(); ++i){
		tong += charToInt(str[i]);
		
	}

	//cout << "kt: "<< str << " size: "<<size  << " tong" << tong << " chiahet" << (tong % 3 == 0)<< endl;

	if(tong % 3 == 0){
		return true;
	}
	return false;
	
}

bool isStringExist(string str){


	for (int i = 0; i < v.size(); ++i){
		if(v[i] == str){
			
			return true;
		}
	}

	return false;
}

string xoaKytu(int i, int len){
	int inc = 0;
	string result = "";
	bool indexToRemove = false;

	for (int j = 0; j < s.size(); ++j){

		indexToRemove = false;
		for (int k = i; k < i+len; ++k){
			if(j == k){
				indexToRemove = true;
				break;
			}
		}

		if(!indexToRemove){
			result += s[j];
		}else{
			inc++;
		}
	}


	if(result[0] == '0' || inc < len || isStringExist(result)){
		return "";
	} 

	if(stringChiaHetThree(result)){
			total++;
	}

	return result;
}
int main(){

	//1005
	
	fi >> s;
	string findString;


	int stringLength = s.size();

	v.push_back(s);

	int len = 1;

	while(len <= stringLength -1){
		for (int i = 0; i < stringLength -1; ++i){
			for (int j = i; j < stringLength; j++){
				findString = xoaKytu(j, len);
				if(findString != ""){
					v.push_back(findString);
				}
			}
		}
		len++;

	}

	fo << total;

	fi.close();
	fo.close();

	return 0;
}