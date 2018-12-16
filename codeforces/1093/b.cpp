#include <iostream> 
#include <string>
using namespace std;

bool isSame(string s){
	for (int i = 1; i < s.size(); ++i){
		if(s[i] != s[i-1]){
			return false;
		}
	}

	return true;
}

bool isPalindromes(string s){
	bool isP = false;
	int i = 0;
	int j = (int)s.size() -1;

	while(s[i] == s[j]){
		if(i >= j){
			isP = true;
			break;
		}

		i++;
		j--;

		
	}

	return isP;
}
void solve(string s){
	if(s.size() == 1){
		cout << "-1";
		return;
	}
	if(isSame(s)){
		cout << "-1";
		return;
	}
	if(!isPalindromes(s)){
		cout << s;
		return;
	}

	char c;
	for (int i = 1; i < s.size(); ++i){
		if(s[i] != s[i-1]){
			
			c = s[i-1];
			s[i-1] = s[i];
			s[i] = c;
			break;
		}
	}

	cout << s;



}

int main(){
	int n;
	string s;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s;
		solve(s);
		cout << endl;
	}
	

	return 0;
}