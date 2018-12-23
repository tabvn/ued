#include <iostream>
#include <stdio.h>
using namespace std;

struct Name
{
	string s;

	Name(string s){
		this->s = s;
	}
	void format(){

		char last = ' ';

		for (int i = 0; i < this->s.size(); ++i){
			if(this->s[i] == ' ' && last == ' '){
				this->s.erase(i, 1);
			}

			if(last == ' ' && this->s[i] != ' '){
				this->s[i] = toupper(this->s[i]);
			}

			last = this->s[i];
		}

	}

	void output(){
		cout <<  this->s;
	}
	
};
int main(int argc, char const *argv[]){
	string s;
	getline(cin, s);
	Name n(s);
	n.format();
	n.output();
	return 0;
}