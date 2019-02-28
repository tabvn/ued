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

	void print(){

		for (int i = 0; i < this->size(); ++i){
			cout << this->get(i) << " ";
		}
	}

	bool isSymability(){


		long long c[this->size()]; // cached 
		if(this->size() == 0 || this->size() == 1){
			return true;
		}

		for (int i = 0; i < this->size(); ++i){
			c[i] = 0;
		}

		for (int i = 0; i < this->size(); ++i){

			c[this->get(i)] ++;
		}

		int thanhPhanKhongChiaHetChohai = 0;

		for (int i = 0; i < this->size(); ++i){
			if(c[this->get(i)] %2 != 0){
				thanhPhanKhongChiaHetChohai ++;
			}
		}

		if(this->size() %2 != 0){
			// so phan tu le
			if(thanhPhanKhongChiaHetChohai == 1){
				return true;
			}
		}else{

			// thanh phan chan
			if(thanhPhanKhongChiaHetChohai == 0){
				return true;
			}
		}
		

		return false;


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

	if(a.isSymability()){
		cout << "TRUE";

		return 0;
	}

	cout << "FALSE";

	return 0;
}