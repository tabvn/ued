#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

class Fraction{

public:

	int tu,mau;
	/**
	* Accept constructor like Fraction("3/4")
	*/
	Fraction(string s){
		this->tu = 0;
		this->mau = 0;

		vector<int> v1;
		vector<int> v2;

		bool acceptedTu = true;

		for (int i = 0; i < s.size(); ++i){
			if(s[i] == '/'){
				acceptedTu = false;
				continue;
			}
			if(acceptedTu == true){
				v1.push_back(this->charToDigit(s[i]));
			}else{
				v2.push_back(this->charToDigit(s[i]));
			}
		}

		reverse(v1.begin(), v1.end()); 
		reverse(v2.begin(), v2.end());


		for (int i = 0; i < v1.size(); ++i){
			this->tu += v1[i] * pow(10, i);
		}

		for (int i = 0; i < v2.size(); ++i){
			this->mau += v2[i] * pow(10, i);
		}


	}

	/**
	* Accept initial as Fraction(3,4)
	*/

	Fraction(int tu, int mau){
		this->tu = tu;
		this->mau = mau;
	}



	int charToDigit(char c){

			//return c - 48;

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

	void print(){
		if(this->tu % this->mau == 0){
			cout << this->tu / this->mau;
			return;
		}
		cout << this->tu << "/" << this->mau;
	}

	int ucln(int a, int b){
		if(a %b ==0) return b;
		if(b %a == 0) return a;

		while(a != b){
			if(a > b){
				b = b;
				a = a-b;
			}else{
				a = a;
				b = b-a;
			}
		}

		return a;
	}

	/*
	* Phep cong
	*/
	Fraction operator + (const Fraction &n){

			int numerator = this->tu * n.mau + n.tu * this->mau;
			int deminator = this->mau + n.mau;
	
			int uc = this->ucln(numerator, deminator);

			Fraction f(numerator/uc, deminator/uc);

			return f;


	}

	/*
	* Phep nhan
	*/
	Fraction operator * (const Fraction &n){

		int numerator = this->tu * n.tu;
		int deminator = this->mau * n.mau;

		int uc = this->ucln(numerator, deminator);

		return Fraction(numerator/uc, deminator/uc);

	}



};

int main(){
	
	string s1, s2;

	cin >> s1 >> s2;

	Fraction f1(s1);
	Fraction f2(s2);

	Fraction f = f1+f2;

	f.print();




	return 0;
}