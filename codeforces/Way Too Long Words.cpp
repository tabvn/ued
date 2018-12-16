#include <iostream> 
#include <string>
using namespace std;

int main(){
	int n;
	string s;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> s;
		if(s.size() <= 10){
			cout << s;
		}else{
			cout << s[0];
			cout << (int)s.size() -2;
			cout << s[(int) s.size()-1];
		}
		cout << endl;
	}
	
	
	return 0;
}