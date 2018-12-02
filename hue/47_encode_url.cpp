#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>

using namespace std;

struct Replacer
{
	int index;
	string replace;
	
};

vector<string> v;

bool canReplace(string s, int index){
	
	int nextIndex = index++;
	int nextTwoIndex = nextIndex++;

	if(nextIndex > (int) s.size() -1 || nextTwoIndex > (int)s.size() -1){
		return true;
	}

	if(s[nextIndex] == '2' && 
		(s[nextTwoIndex] == '0' || s[nextTwoIndex] == '1' 
			|| s[nextTwoIndex] == '4' || s[nextTwoIndex] == '5' 
			|| s[nextTwoIndex] == '8' || s[nextTwoIndex] == '9' || s[nextTwoIndex] == 'a')){
		return false;
	}
	return true;
}

string _replace(string s){

	// replace % first
	vector<int> percentIndexes;
	vector<Replacer> replaces;
	Replacer replacer;
	
	for (int i = 0; i < s.size(); ++i){
		int nextIndex = i+i;
		if(s[i] == '%' && canReplace(s, i)){
			percentIndexes.push_back(i);
		}
	}

	

	// replace % dau tien tranh nham lan ve sau

	int numOfReplace = 0;
	for (int i = 0; i < percentIndexes.size(); ++i){
		int indexToreplace = percentIndexes[i]+numOfReplace;
		s.replace(indexToreplace, 1,"%25");
		numOfReplace += 2;
	}

	// replace cac ki tu khac

	for (int i = 0; i < s.size(); ++i){
	
		if(s[i] == '%' && canReplace(s, i)){
			percentIndexes.push_back(i);
		}
		else if(s[i] == ' '){
				replacer.index = i;
				replacer.replace = "%20";
				replaces.push_back(replacer);

		}
		else if(s[i] == '!'){
				replacer.index = i;
				replacer.replace = "%21";
				replaces.push_back(replacer);
		}
		else if(s[i] == '$'){
				replacer.index = i;
				replacer.replace = "%24";
				replaces.push_back(replacer);
		}
		else if(s[i] == '('){
				replacer.index = i;
				replacer.replace = "%28";
				replaces.push_back(replacer);
		}
		else if(s[i] == ')'){
				replacer.index = i;
				replacer.replace = "%29";
				replaces.push_back(replacer);
		}
		else if(s[i] == '*'){
				replacer.index = i;
				replacer.replace = "%2a";
				replaces.push_back(replacer);
		}
	}


	numOfReplace = 0;
	for (int i = 0; i < replaces.size(); ++i){

			int indexReplace = replaces[i].index + numOfReplace;
			s.replace(indexReplace,1, replaces[i].replace);
			numOfReplace += 2;
	}

	
	return s;
}

int main(){
	string s;
	int n;

	cin >> n;
	getline(cin,s);
	for (int i = 0; i < n; ++i){
		getline(cin, s);
		v.push_back(s);
	}

	for (int i = 0; i < v.size(); ++i){
		//cout << "i:" << i << " "<< v[i] << endl;
		cout << "Case #"<<(i+1)<<": " << _replace(v[i]) << endl;
	}

	return 0;
}