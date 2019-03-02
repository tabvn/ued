#include <iostream>
using namespace std;


class Array
{

private:

	int _size;
	long long *items;
	long long _cursor;


public:

	Array(int size){
		_cursor =0;
		_size = size;
		items = new long long[size];
	}

	void push(long long item){
		items[_cursor] = item;
		_cursor++;
	}

	void set(int index, long long item){
		this->items[index] = item;
	}

	long long get(int index){

		return this->items[index];
	}

	int size(){

		return _size;
	}

	bool isSupascen(){

		if(this->size() < 2){
			return false;
		}

		long long s = this->get(0);
		long long num;

		for (int i = 1; i < this->size(); ++i){
			num = this->get(i);
			
			if(num < s){
				return false;
			}

			s+= num;
		}

		return true;


	}


	void print(){

		for (int i = 0; i < this->size(); ++i){
			cout << this->get(i) << " ";
		}
	}

	/*
	* Deconstructor
	*/
	~ Array(){
		
		delete[] this->items;
	}
	
};


int main(){
	
	int n;
	long long tmp;

	cin >> n;

	Array a(n);

	for (int i = 0; i < n; ++i){
		cin >> tmp;
		a.push(tmp);
	}

	if(a.isSupascen()){
		cout << "TRUE";

		return 0;
	}

	cout << "FALSE";

	return 0;
}