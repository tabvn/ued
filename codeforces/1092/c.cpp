#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Tabvn{
	int len;

	vector<string> strings;
	vector<string> results;
	vector<string> originalStrings;
	string foundString;
	map<string,char> checked;

	void begin(int n){
		this->foundString = "";
		this->len = n;

		string s1 = "";
		for (int i = 0; i < len; ++i){
			s1+= "*";
		}

		this->results.push_back(s1);

	}
	void add(string s){
		this->checked.insert(pair<string, char>(s, '*'));
		this->originalStrings.push_back(s);
		this->strings.push_back(s);
	}


	bool check(string s){
		int i = 0;
		int j = (int) s.size() -1;

		while(s[i] != '*' && s[j] != '*'){

			if(i > j){
				return true;
			}

			i++;
			j--;

		}

		return false;
	}
	void addToResult(string s){
		bool isRemoved = false;
		vector<string> addStrings;
		string leftToRightString;
		string rightToLeftString;

		for (int i = 0; i < results.size(); ++i){

				string leftToRightString = results[i];
				string rightToLeftString = results[i];

				// left to right
				isRemoved = false;

				for (int j = 0; j < s.size(); ++j){
					if(leftToRightString[j] == s[j]){
						continue;
					}
					if(leftToRightString[j] == '*'){
						leftToRightString[j]  = s[j];
					}else{

						isRemoved = true;
						break;
					}
				}

				
				if(!isRemoved){
					addStrings.push_back(leftToRightString);
					if(this->check(leftToRightString)){
						this->foundString = leftToRightString;
						break;
					}

					

					
				}

				// right to left
				isRemoved = false;

				int inc = rightToLeftString.size() -1;
				for (int j = (int)s.size() -1; j >=0; --j){

					if(rightToLeftString[inc] == '*' || rightToLeftString[inc] == s[j]){
						rightToLeftString[inc] = s[j];
					}
					else{
						isRemoved = true;
						break;
					}
					
					inc--;
				}

				if(!isRemoved){
					addStrings.push_back(rightToLeftString);
					if(this->check(leftToRightString)){
						this->foundString = leftToRightString;
						break;
					}

					

				}


		}

		// remove strings if not fit 
		this->results.clear();
		if(addStrings.size() > 0){
			for (int i = 0; i < addStrings.size(); ++i){
				results.push_back(addStrings[i]);
			}
		}
		addStrings.clear();


	}

	bool isPrefix(string s){
		//cout << "check: " << s << " " << this->foundString << endl;

		char lastCheck = this->checked.at(s);

		//cout << "last check " << s << " " << lastCheck << endl;
		bool prefix = true;

		
		for (int i = 0; i < s.size(); ++i){
			if(s[i] != this->foundString[i]){
					
				prefix = false;
				break;
				
			}
		}

		if(lastCheck == 'P'){
			prefix = false;
		}

		return prefix;
	}

	void solve(){

		for (int i = 0; i < this->strings.size(); ++i){

			this->addToResult(this->strings[i]);
		}

		// let check every and guess it is prefix or subffix
		string s;
		for (int i = 0; i < this->originalStrings.size(); ++i){
			s = this->originalStrings[i];
			//cout << "check: " << s << " " << this->foundString<< " ";

			if(this->isPrefix(s)){
				cout << "P";
				this->checked[s] = 'P';

			}else{
				this->checked[s] = 'S';
				cout << "S";
			}

			
		


		}

	}



};


Tabvn t;

bool handleSort(string a, string b){
	return a.size() > b.size();
}

int main(int argc, char const *argv[]){
	int n;
	string s;
	cin >> n;

	t.begin(n);

	for (int i = 0; i < n*2 - 2; ++i){
			cin >> s;
			t.add(s);
	}

	sort(t.strings.begin(), t.strings.end(), handleSort);

	// solve problem
	t.solve();


	return 0;
}