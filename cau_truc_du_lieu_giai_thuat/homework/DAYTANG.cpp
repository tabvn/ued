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


	int findLongest(){

		if(this->size() == 0){
			return 0;
		}
		int max = 1;
		int maxSofar = 1;

		for (int i = 1; i < this->size(); ++i){
			if(this->get(i) >= this->get(i-1)){
				maxSofar++;
			}else{
				if(maxSofar > max){

					max = maxSofar;
					maxSofar = 1;
				}
			}
		}

		return max;
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


	cout << a.findLongest();

	return 0;
}