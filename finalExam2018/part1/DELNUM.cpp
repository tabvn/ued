#include <iostream>
#include <string>
using namespace std;

bool isNumber(char c){
	
	if(c == '0' || c == '1' || c == '2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c == '8' || c=='9'){
		return true;
	}

	return false;
}
int main(){

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i){
		if(isNumber(s[i]) == true){
			continue;
		}
		cout << s[i];
	}

	return 0;
}