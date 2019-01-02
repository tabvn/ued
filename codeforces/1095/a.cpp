#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<char> v;

int main(int argc, char const *argv[]){
	
	int n;
	string s;


	cin >> n;
	cin >> s;

	if(n == 1){
		cout << s;
		return 0;
	}


	v.push_back(s[0]);
	int index = 1;
	for (int i = 1; i < s.size(); ++i){
		if(index == v.size() +1){
				v.push_back(s[i]);
				index = 1;
		}
		index++;

	

	}
	for (int i = 0; i < v.size(); ++i){
		cout << v[i];
	}

	return 0;
}