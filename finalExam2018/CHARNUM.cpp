#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool isDigit(char c){

	if(c == '0' || c == '1' || c=='2' || c=='3' || c == '4' || c == '5' || c=='6' || c == '7' || c=='8' || c=='9')
	{
		return true;
	}

	return false;
}

int main(){
	string s;
	unsigned long long total = 0;	
	getline(cin, s);
	for (unsigned long long i = 0; i < s.size(); ++i){
		if(isDigit(s[i])){
			total++;
		}

	
	}
	cout << total;

	return 0;
}