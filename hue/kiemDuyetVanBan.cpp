#include <iostream> 
#include <string>
#include <algorithm>

using namespace std;

string s;
string filterString;
void _replace(){
	string::size_type i = s.find(filterString);
	while(true){
		i = s.find(filterString);
		if (i != string::npos){
			s.erase(i, filterString.length());
		}else{
			break;
		}
	}
	
}
int main(){

	cin >> s >> filterString;
	if(filterString.size() > s.size() || (filterString.size() == s.size() && s != filterString) ){
		cout << s;
	}else{
		_replace();
		cout << s;
	}
	
	return 0;
}