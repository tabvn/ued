#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int len = 1;
string s;
vector<int> v;
int commaIndex = -1;
bool remember = 0;


int paseInt(char c){

	switch(c){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}
void lamTron(){

	int _len = 0;
	int theIndex = -1;
	bool shoudIncreaseIndex = false;

	for (int i = 0; i < s.size(); ++i){

		if(shoudIncreaseIndex){
			_len++;
		}

		if(s[i] != '.'){
			v.push_back(paseInt(s[i]));
		}else{
			commaIndex = i;
			shoudIncreaseIndex = true;
		}

		
		if(_len == len){
			// vi tri cần làm tron
			theIndex = i;
			// kiem tra chu so ke tiep
			int nextIndex = i+1;
			if(nextIndex <= s.size() -1){
				if(paseInt(s[nextIndex]) >= 5){
					remember = 1;
				}
			}

			break;
		}

	}

	// bắt đầu làm tròn ta tiến hành từ phải sang trái

	for(int i = v.size() -1; i >= 0; i--){
		if(remember){
			remember = 0;
			v[i] += 1;
			if(v[i] >= 10){
				int prevIndex = i -1;
				if(prevIndex >= 0){
					v[i] = 0;
					remember= 1;
				}
			}
		}
	}

	// display

	int lastIndex = v.size() -1;
	for (int i = 0; i < v.size(); ++i){
		if(i == commaIndex){
			cout << '.';
		}
		cout << v[i];
		
	}
}



int main(){
	
	// 2.78999
	cout << "Nhap So: ";
	cin >> s;
	cout << "Ban muon lam tron den bao nhieu chu: ";
	cin >> len;
	lamTron();

	return 0;
}