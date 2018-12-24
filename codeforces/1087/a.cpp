#include <iostream>
#include <string> 
#include <vector>
using namespace std;

void evenString(string s){
	int i = 0;
	int j = s.size() -1;
	int len = 0;
	vector<char> v;

	while(len < s.size()){
		v.push_back(s[j]);
		v.push_back(s[i]);
		i++;
		j--;
		len += 2;
	}

	for (int i = (int)v.size() -1; i >= 0 ; --i){
		cout << v[i];
	}

}

void oddString(string s){
	int i = 0;
	int j = s.size() -1;
	int len = 0;
	vector<char> v;

	while(true){


		if(i == j){
			v.push_back(s[i]);
			break;
		}
		v.push_back(s[i]);
		v.push_back(s[j]);

		i++;
		j--;
		
	}

	for (int i = (int)v.size() -1; i >= 0 ; --i){
		cout << v[i];
	}

}


int main(int argc, char const *argv[]){
	string s;
	cin >> s;

	if(s.size() == 1 || s.size() == 2){
		cout << s;
		return 0;
	}

	if((int)s.size() % 2 == 0 ){
		evenString(s);
	}else{
		oddString(s);

	}

	return 0;
}