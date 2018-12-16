#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
	string s;
  cin >> s;
  char c;
  bool all_is_uppercase = true;

  for (int i = 0; i < s.size(); ++i){
  	if(i ==0){
  		continue;
  	}
  	c = toupper(s[i]);

  	if (c != s[i]){

  		
  		all_is_uppercase = false;
  	}

  }

  if(all_is_uppercase){
  	for (int i = 0; i < s.size(); ++i){
  		if(i == 0){
  			if(toupper(s[i]) == s[i]){
  				c = towlower(s[i]);
  			}else{
  				c = toupper(s[i]);
  			}
  			
  		}else{
  			c = towlower(s[i]);
  		}

  		cout << c;
  	}
  }else{

  	cout << s;
  }
	return 0;
}