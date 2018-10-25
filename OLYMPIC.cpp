#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("OLYMPIC.INP");
ofstream fo ("OLYMPIC.OUT");

struct Node{
	long int a,b;
	bool isDone;
};

long int c;
int score = 0;

Node node;
vector<Node> v;


void doHomework(){

	for (int i = 0; i < v.size(); ++i){
		if(v[i].isDone){
			// da giai roi thi ko can giai lai
			continue;
		}

		if(c >= v[i].a){
			// du kha nang giai bai tap

			c+= v[i].b;
			v[i].isDone = true;
			score++; // tang them so luong bai da giai dc

			// tiep tuc giai bai khac dung de quy
			doHomework();
		}
	}
}

int main(){

	int n;
	long int a,b;

	fi >> n >> c;

	for (int i = 0; i < n; ++i){
		fi >> a >> b;
		node.a = a;
		node.b = b;
		node.isDone = false;
		v.push_back(node);
	}

	doHomework();

	fo << score; // write output to file

	fi.close();
	fo.close();
	
	return 0;
}