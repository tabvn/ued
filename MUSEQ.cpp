#include <iostream> 
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fi ("MUSEQ.INP");
ofstream fo ("MUSEQ.OUT");

struct Num{
	long int value;
	int index;

};


struct SEQ{
	vector<Num> vOrigin;
	vector<Num> vsort;
	vector<Num> vResult;
};

vector<SEQ*> arr;
Num num;

bool ascSort(Num a, Num b){

	return a.value  < b.value;
}

void processFindSeq(){

	long int value = 1;

	for (int i = 0; i < arr.size(); ++i){
		//SEQ *seq = arr[i];

		num.value = 1;
		num.index = arr[i]->vsort[0].index;

		arr[i]->vResult.push_back(num);

		for (int j = 1; j < arr[i]->vsort.size(); ++j){
			value = arr[i]->vResult[j-1].value;
			if(arr[i]->vsort[j].value > arr[i]->vsort[j-1].value){
				// tang len 1
				value ++;
			}

			num.value = value;
			num.index = arr[i]->vsort[j].index;
			arr[i]->vResult.push_back(num);

		}
	}
}

long int findResultNumAtIndex(SEQ *seq, int _index){

	for (int i = 0; i < seq->vResult.size(); ++i){
			if(seq->vResult[i].index == _index){
				return seq->vResult[i].value;
			}
	}

	return 0;
}

void print(){

	for (int i = 0; i < arr.size(); ++i){
		SEQ *seq = arr[i];
		for (int j = 0; j < seq->vOrigin.size(); ++j){
			fo << findResultNumAtIndex(seq, seq->vOrigin[j].index) << " ";
		}
		fo << endl;
	} 
}

int main(){
	
	int t,n;
	long int ai;
	fi >> t;

	for (int i = 0; i < t; ++i){
		fi >> n;

		SEQ *seq = new SEQ();

		for (int j = 0; j < n; ++j){
			fi >> ai;
			// them vao ca 2 mang. 1 cai dung de sort thap len cao
			num.value = ai;
			num.index = j;

			seq->vOrigin.push_back(num);
			seq->vsort.push_back(num);
		}
		sort(seq->vsort.begin(), seq->vsort.end(), ascSort);
		arr.push_back(seq);

	}
	processFindSeq();
	print();
	fi.close();
	fo.close();

	return 0;
}