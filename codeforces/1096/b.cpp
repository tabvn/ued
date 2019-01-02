#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Seq
{
	char c;
	long long length;
	
};

vector<Seq> v;

Seq seq;

int main(){
	int n;
	char ch,lastChar;
	cin >> n;

	seq.length = 0;

	for (int i = 0; i < n; ++i){
		cin >> ch;
		if(i ==0){
			seq.c = ch;
		}
		if(i != 0 && lastChar != ch){
			v.push_back(seq);
			seq.c = ch;
			seq.length = 0;
		}
	
		seq.length ++;
		lastChar = ch;

		if(i == n-1){
			v.push_back(seq);
		}

	}

	int lastIndex = (int)v.size() -1;
	long long total = 3;

	if(v[0].c == v[lastIndex].c){
		total += 1;
		long long l = v[0].length ;
		long long r = v[lastIndex].length;
		total += (l*r)  - 1;
		
	}

	total += v[lastIndex].length -1;
	total += v[0].length -1;

	cout << (total % 998244353);


	return 0;
}