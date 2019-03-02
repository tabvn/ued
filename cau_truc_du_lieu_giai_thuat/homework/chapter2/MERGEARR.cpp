#include <iostream>
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

	Array merge(Array &a){

		int newSize = this->size() + a.size();
		Array arr(newSize);

		int i = 0;
		int j = 0;

		while(i < this->size() && j < a.size()){

			if(this->get(i) < a.get(j)){
				arr.push(this->get(i));
				i++;
			}else{
				arr.push(a.get(j));
				j++;
			}
		}

		while(i < this->size()){
			arr.push(this->get(i));
			i++;
		}
		while(j < a.size()){
			arr.push(a.get(j));
			j++;
		}

		return arr;
	}

	void print(){

		for (int i = 0; i < this->size(); ++i){
			cout << this->get(i) << " ";
		}
	}
	
};
int main(){

	int m,n,tmp;
	cin >> m >> n;

	
	Array a(m);
	Array b(n);

	for (int i = 0; i < m; ++i){
			cin >> tmp;
			a.push(tmp);
	}

	for (int i = 0; i < n; ++i){
			cin >> tmp;
			b.push(tmp);
	}
	
	
	cout << m+n << endl;
	a.merge(b).print();


	return 0;
}