#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
/Users/toan/ued/18-10-2018
*/

ifstream fi ("FAIRPLAY.INP");
ofstream fo ("FAIRPLAY.OUT");

vector<long int> v1;
vector<long int> v2;

bool descSort(long int a, long int b){
	return a > b;
}

int main(){
	int n;
	long int a, score;

	fi >> n;

	score = 0;

	for (int i = 0; i < n; ++i){
		fi >> a;
		v1.push_back(a);
	}

	for (int i = 0; i < n; ++i){
		fi >> a;
		v2.push_back(a);
	}
	// sap xep giam dan 2 mang
	sort(v1.begin(), v1.end(), descSort);
	sort(v2.begin(), v2.end(), descSort);
	// ta lan luot lay vi tri cua mang thu 2 dem dau voi mang 1,

	for (int i = 0; i < v2.size(); ++i){
		for (int j = 0; j < v2.size(); ++j){
			if(v1[j] == -1 || v1[i] == v2[j]){
				continue;
			}
			else if(v2[i] > v1[j]){
				score++;
				// dong thoi danh dau la vi tri nay da dau xong
				v1[j] = -1;
				break; // dung lai de tiep tuc cap khac

			}else{
				// danh dau la so suc manh doi nay cao qua va bo qua cap nay
				v1[j] = -1;
			}
		}
	}

	fo << score;


	fi.close();
	fo.close();
	return 0;
}