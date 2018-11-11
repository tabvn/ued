#include <iostream> 
#include <string>
#include <vector>
using namespace std;

int findIndexString(string a, char c){

	for (int i = 0; i < a.size(); ++i){
		if(a[i] == c){
			return i;
		}
	}

	return -1;

}
void findAnagram(string a, string b){
	int aLength = (int)a.size();
	bool checkArr[aLength];

	int maxLength = 0;
	int stringLength = 0;
	for (int i = 0; i < b.size(); ++i){
		int _index = findIndexString(a, b[i]);
		
		if(_index !=-1 && checkArr[_index] != true){
			// danh dau la da chuyen

			//cout << "found: " << b[i] << " " << a[_index] << " " << _index << endl;
			stringLength ++;
			checkArr[_index] = true;
			// ta tiep tuc kiem tra
		}else{
			if(stringLength> maxLength){
				maxLength = stringLength;
				stringLength = 0;
			}
		}
	}

	for (int i = b.size() -1; i > 0; --i){
		int _index = findIndexString(a, b[i]);
		
		if(_index !=-1 && checkArr[_index] != true){
			// danh dau la da chuyen
			//cout << "found: " << b[i] << " " << a[_index] << " " << _index << endl;
			stringLength ++;
			checkArr[_index] = true;
			// ta tiep tuc kiem tra
		}else{
			if(stringLength> maxLength){
				maxLength = stringLength;
				stringLength = 0;
			}
		}
	}

	cout << maxLength;
}
int main(){

	string a,b;

	cin >> a;
	cin >> b;

	findAnagram(a, b);
	return 0;
}