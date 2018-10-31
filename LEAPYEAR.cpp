#include <iostream> 
#include <fstream>
using namespace std;

ifstream fi ("LEAPYEAR.INP");
ofstream fo ("LEAPYEAR.OUT");


bool isLunarLeapYear(int n){

	int divisble = n%19;

	if(divisble == 0){
		return true;
	}
	else{
		//3, 6, 9, 11, 14, 17
		if(divisble == 3 || divisble == 6 || divisble == 9 || divisble == 11 || divisble == 14 || divisble == 17){
			return true;
		}
	}
	return false;
}

int main(){

	int a,b;
	int total = 0;


	fi >> a >> b;

	
	for (int i = a; i <=b; ++i){
		
		if(isLunarLeapYear(i)){
			total++;
		}

	}

	fo << total;

	fi.close();
	fo.close();

	return 0;
}
