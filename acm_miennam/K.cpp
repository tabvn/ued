#include <iostream>
#include <string>
using namespace std;


int charToNum(char c){

	switch(c){

			case  '1':

				return 1;

			case '2':

				return 2;

			case '3': 

				return 3;

			case '4':

			return 4;

			case '5':

				return 5;

			case '6':

				return 6;

			case '7':

				return 7;

			case '8':
				return 8;

			case '9':
			
				return 9;

			case '0':
				return 0;			

		default: 

			return 0;
	}

}

string s;


int main(){
	
	cin >> s;

	int digit;

	for (int i = s.size() - 1; i >=0 ; i--){
		digit = charToNum(s[i]);
		int remeber = 0;
		if(digit > 8){
			s[i] = '8';

			for (int k = i +1; k < s.size(); ++k){
				s[k] = '8';
			}

		}
		
		else if(digit == 8){
			s[i] = 8;
		}
		else if(digit > 6  && digit < 8){
			s[i] = '6';
			// cac so sau no phai = 8
			for (int k = i +1; k < s.size(); ++k){
				s[k] = '8';
			}
		}
		else if(digit == 6){
			s[i] = '6';
		}
		else if (digit < 6){
			remeber = 1;
			for (int j = i -1; j >= 0; --j){
				int d = charToNum(s[j]);
				if(d > 6){
					s[j] = '6';
					remeber = 0;
					
					// tat ca so su cung la 8
					for (int k = j+1; k < s.size(); ++k){
						s[k] = '8';
					}

					break;
				}
				if(d < 6){
					s[j] = '8';	
					remeber =1;
				}
			}

			if(remeber >0){
				// ta phai tien hanh xoa 1 so
				s.erase(0,1);
				// cac so sau se = 8
				for (int k = 0; k < s.size(); ++k){
					s[k] = '8';
				}
			}
		}


	}

	cout << s;
	

	return 0;
}