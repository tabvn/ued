#include <iostream> 
#include <string>

using namespace std;

int charToInt(char c){

	

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
int main(){
	
	long long n;
	char c, lastChar;

	string s;

	cin >> n;

	long long maxLen = 0;
	long long len = 0;

	lastChar = -1;

	for (long long i = 0; i < n; ++i){

		cin >> c;

		if(i == 0){
			len++;
			lastChar = c;

			continue;
		}

	
		if((charToInt(c) + charToInt(lastChar)) == 1){
			if(len == 0){
				len = 1;
			}
			len++;

			if(len > maxLen){
				maxLen = len;
			}
		}else{
			if(len > maxLen){
				maxLen = len;
			}

			len = 1;
		}

		lastChar = c;
	}

	if(maxLen == 0){
		maxLen = len;
	}

	cout << maxLen;

	return 0;
}