#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>

using namespace std;

int firstValue(char c){

//𝟸,𝟹,𝟺,𝟻,𝟼,𝟽,𝟾,𝟿,𝚃,𝙹,𝚀,𝙺,𝙰
	switch(c){
		
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'T': return 10;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
		case 'A': return 14;

		default: return 0;
	}

	return 0;
}

int secondValue(char c){

	//𝙳,𝙲,𝚂,𝙷

	switch(c){

		case 'D': return 1;
		case 'C': return 2;
		case 'S': return 3;
		case 'H': return 4;
		default: return 0;
	}

	return 0;
}
int main(){
	
	string first, second = "";

	cin >> first;

	int fValue = 0;
	int value = 0;

	bool isOk = false;

	for (int i = 0; i < 5; ++i){

		cin >> second;

		if(secondValue(second[1]) == secondValue(first[1]) || firstValue(second[0]) == firstValue(first[0])){
			isOk = true;
		}
		
		
	}

	if(isOk){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}