#include <iostream>
#include <string>
using namespace std;


bool isP(string s, int left, int right){
		if(s.size() ==1 || left >= right){
			return true;
		}

		if(s[left] != s[right]){
			return false;
		}

		return isP(s, left+1, right-1);
}

int main(){
	
	string s;

	cout << "Nhap chuoi can kiem tra: ";

	cin >> s;

	if(isP(s, 0 , s.size() -1)){
		cout << "Chuoi doi xung";
	}else{
		cout << "Chuoi khong doi xung";
	}
	return 0;
}