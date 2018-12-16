#include <iostream> 
#include <string>
using namespace std;

string s;

bool sameCharacters(){

	char c = s[0];
	for (int i = 1; i < s.size(); ++i){
		if(s[i] != c){

			return false;
		}
	}

	return true;

}

void solve(){

	if(sameCharacters()){
		cout << s;
		return;
	}

	string maxStr = "";
	string str = "";

	long long lastIndex = -1;
	long long lastEndIndex = (int)s.size();

	for (int i = 0; i < s.size(); ++i){
		
		bool found = false;

		for (int j = lastEndIndex - 1; j > i; --j){
			if(s[j] == s[i]){
				lastIndex = i;
				lastEndIndex = j;
				found = true;
				break;
			}
		}
		if(found){
			str += s[lastIndex];
		}
		if(str.size() > maxStr.size()){
			maxStr = str;
		}
	}

	int stringSize = (int)maxStr.size() * 2 + 1;
	char arr[stringSize];
	int j;
	for (int i = 0; i < (int)maxStr.size(); ++i){
		arr[i] = maxStr[i];
		j = stringSize - i -1;
		arr[j] = maxStr[i];
	}
	arr[(int)maxStr.size()] = s[lastIndex+1];
	for (int i = 0; i < stringSize; ++i){
	 	cout << arr[i];
	} 


}

int main(int argc, char const *argv[]){
	cin >> s;
	solve();
	return 0;
}