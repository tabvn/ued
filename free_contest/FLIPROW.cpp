#include <iostream> 
#include <vector>
using namespace std;

vector<long int> v;

int main(int argc, char const *argv[]){
	int row,column;

	cin >> row >> column;
	long int a[row][column];

	for (int i = 0; i < row; ++i){
		
		for (int j = 0; j < column; ++j){
			cin >> a[i][j];
		}
	}


	int cot = 0;
	int hang = 0;
	while(cot < column){
		for (int i = 0; i < row; ++i){
			cout << a[hang][i] << " ";
			hang ++;
		}
		cout << endl;

		hang = 0;
		cot ++;
	}



	return 0;
}