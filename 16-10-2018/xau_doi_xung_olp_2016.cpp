#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
string xau;
vector<int> v;

bool doiXung(string s, int length){

	int i,j;
	i = 0;
	j = length -1;

	while(s[i] == s[j]){
		i++;
		j--;

		if(i >= j){

			return true;
		}
	}

	return false;
}

int main(){

	int q, li;

	getline(cin, s);

	cin >> q;

	for (int i = 0; i < q; ++i){

		cin >> li;

		v.push_back(li);
	}

	int sSize = s.size();
	int xauSize = 0;
	bool dx = false;

	for (int i = 0; i < v.size(); ++i){
		li = v[i]; // do xai xau
		dx = false;
		for(int j = 0; j< sSize; j++){
			xau = "";
			xauSize = 0;
			

			for(int k = j; k < j+li; k++){
				xau += s[k];
				xauSize++;
			}
			if(xauSize == li){
				// kiem tra xem co doi xung ko
				if(doiXung(xau, xauSize)){
					dx = true;
				}
			}
			//cout << xau << endl;
			
		}

		if(dx){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}


	}

	return 0;
}