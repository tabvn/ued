#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
	
	string s;


	cin >> s;

	bool yes = false;

	for (int i = 0; i < s.size(); ++i){
		if(s[i] == 'H' || s[i]== 'Q' || s[i] == '9' || s[i]== '+'){
			yes = true;
			break;
		}
	}

	if(yes){
		cout << "YES";
	}else{

		cout << "NO";
	}

	return 0;
}