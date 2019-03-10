#include <iostream>
using namespace std;

class Serial{

private:

	static int count;
	int key;

public:

	Serial(){
		count ++;
		key = count;
	}

	int getKey(){
		return key;
	}

	int getCount(){
		return this->count;
	}

};


int Serial::count = 0;

int main(){

	Serial s1, s2, s3;
	

	cout << "Class 1 has key: " << s1.getKey() << endl;
	cout << "class 2 has key: " << s2.getKey() << endl;
	cout << "class 3 has key: " << s3.getKey() << endl;

	cout << "Num of classes: " << s1.getCount();
	

	return 0;
}