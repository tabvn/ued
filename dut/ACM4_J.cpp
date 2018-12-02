#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;

	cin >> s;

	bool isNiceNumber = true;
	for (int i = 0; i < s.size(); ++i){
		if(s[i] != '4' && s[i] != '7'){
			isNiceNumber = false;
			break;
		}
	}
	if(isNiceNumber){
		cout << "YES";

	}else{
		cout << "NO";
	}

	return 0;
}