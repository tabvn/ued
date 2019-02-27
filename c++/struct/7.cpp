#include <iostream>
using namespace std;

struct Fraction{
	int numerator, denominator;
	
	int ucln(int a, int b){
		if(a %b == 0){
			return b;
		}
		if(b %a == 0){
			return a;
		}

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

	Fraction operator +(const Fraction &b){

		int n = (this->numerator * b.denominator) + (b.numerator* this->denominator);
		int d = this->denominator *b.denominator;
		int uc = this->ucln(n, d);

		n = n/uc;
		d = d/uc;

		Fraction sum = {n,d};

		return sum;
	}

	Fraction operator *(const Fraction &b){

			Fraction m;

			m.numerator = this->numerator * b.numerator;
			m.denominator = this->denominator * b.denominator;

			int uc = this->ucln(m.numerator, m.denominator);

			m.numerator /= uc;
			m.denominator /= uc;

			return m;
	}


	void print(){
		cout << this->numerator << "/" << this->denominator;
	}
};


int main(){
	
	Fraction a = {1, 2};
	Fraction b = {2, 2};
	Fraction c = a +b;

	c.print();



	return 0;
}