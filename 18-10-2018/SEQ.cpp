#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("/Users/toan/ued/18-10-2018/SEQ.INP");
ofstream fo ("/Users/toan/ued/18-10-2018/SEQ.OUT");

struct Block{
	vector<long int> v;

};

Block block;

vector<long int> v;
vector<Block> blockArr;

int findNumIndexInBlock(long int num){

	for (int i = 0; i < block.v.size(); ++i){
		if(block.v[i] == num){
			return i;
		}
	}

	return -1;
}


void find(){

	block.v.clear();

	for (int i = 0; i < v.size(); ++i){

		for (int j = i; j < v.size(); ++j){

			if(findNumIndexInBlock(v[j]) > -1){
				// ton tai nen doan nay khong lien tuc nua.
				// ta bo qua
				blockArr.push_back(block);
				block.v.clear();


				break;

			}else{

				cout << v[j];
				block.v.push_back(v[j]);
			}
		}
		// them vao mang block

		

	}

}
int main(){
	long int a;
	long long n;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> a;
		cout << a;
		v.push_back(a);
	}

	

	find();


	for (int i = 0; i < blockArr.size(); ++i){
				
				block = blockArr[i];

			for (int j = 0; j < block.v.size(); ++j){
					cout << block.v[j] << " ";
			}
			cout << endl;

	}

	return 0;
}