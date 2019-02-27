#include <iostream>
#include <math.h>
using namespace std;

struct Array
{

	int _size;
	int *items;
	int _cursor;

	Array(int size){
		_cursor =0;
		_size = size;
		items = new int[size];
	}

	void push(int item){
		items[_cursor] = item;
		_cursor++;
	}

	void set(int index, int item){
		this->items[index] = item;
	}
	int get(int index){

		return this->items[index];
	}

	int size(){
		return _size;
	}

	int findDiffLength(){

		int c[this->size()]; // cache array 
		int duplicateNumbers = 0;

		for (int i = 0; i < this->size(); ++i){

			if(c[this->get(i)] == 1){
				// found dulicated number before
				duplicateNumbers++;
			}else{
				c[this->get(i)] = 1;
			}
		}

		return this->size() - duplicateNumbers;

	}
	void print(){

		for (int i = 0; i < this->size(); ++i){
			cout << this->get(i) << " ";
		}
	}
	
};



int main(){

	
	int n,tmp;
	cin >> n;
	
	Array a(n);

	for (int i = 0; i < n; ++i){
		cin >> tmp;
		a.push(tmp);

	}	


	cout << a.findDiffLength();



	return 0;
}