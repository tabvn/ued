#include <iostream> 
#include <string>
#include <stdio.h>
using namespace std;

bool is_consonants(char c){
	if(c == 'a' || c== 'o' || c == 'y' || c=='e' || c=='u' || c=='i'){
		return true;
	}

	return false;
}

int main(){
	string s;
	cin >>s;

	//"A", "O", "Y", "E", "U", "I"

	char c;

	for (int i = 0; i < s.size(); ++i){
		c = tolower(s[i]);
		if(!is_consonants(c)){
			cout << ".";
			cout << c;
		}

	}
	return 0;
}