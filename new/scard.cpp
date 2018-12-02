#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fi ("SCARD.INP");
ofstream fo ("SCARD.OUT");

// cac phong 
struct Node
{
	vector<long int> nums;
};

vector<long int> card;// chua cac day so bi mat
vector<Node*> nodes; // chua cac day so tung phong
vector<int> results; // chua vi tri phong co the mo dc


long int ucln(long int a, long int b){

	if(a %b == 0){
		return b;
	}
	else if(b%a == 0){
		return a;
	}else{
		long int tmp;
    while(b != 0) {
      tmp = a % b;
      a = b;
      b = tmp;
    }
    return a;

	}

}
bool isAllNumEqualToOne(vector<long int> v){

	for (int i = 0; i < v.size(); ++i){
		if(v[i] != 1){
			return false;
		}	
	}

	return true;
}


bool canOpen(vector<long int> v, Node *node){

	if(isAllNumEqualToOne(node->nums)){
		return true;
	}

	if(isAllNumEqualToOne(v)){
		// neu tat ca the co ma = 1 thi ko the mo dc
		return false;
	}

	long int uc;
	bool hasUc = false;

	for (int i = 0; i < v.size(); ++i){
		if(v[i] == 1){
			continue;
		}

		for (int j = 0; j < node->nums.size(); ++j){
			uc = ucln(v[i], node->nums[j]);
			if(uc > 1){
				// chia dong thoi ca 2 cho uoc chung
				v[i] /= uc;
				node->nums[j] = node->nums[j]/uc;
				hasUc = true;
				break;
			}

		}
	}

	if(!hasUc){
		return false;
	}
	
	return canOpen(v, node);
}


bool descSort(long int a, long int b){
	return a > b;
}

int main(){

	int m,n;
	long int num;

	fi >> m >> n;


	for (int i = 0; i < m; ++i){
		fi >> num;
		card.push_back(num);
	}

	sort(card.begin(), card.end(), descSort);

	for (int i = 0; i < n; ++i){
		Node *node = new Node();

		for (int j = 0; j < m; ++j){
			fi >> num;
			
			node->nums.push_back(num);
		}

		sort(node->nums.begin(), node->nums.end(), descSort);
		nodes.push_back(node);
	}

	for (int i = 0; i < nodes.size(); ++i){
		if(canOpen(card, nodes[i])){
			results.push_back(i);
		}
	}

	int total = (int)results.size();
	
	fo << total << endl;
	for (int i = 0; i < results.size(); ++i){
		fo << (results[i] +1) << " ";
	}
	
	fo.close();
	fi.close();

	return 0;
}