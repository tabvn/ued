#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Seq{
	vector<long int> v;
};


Seq seq;

vector<long int> v;
vector<Seq> vSeq;

long long ucln(long long a, long long b){

	if(a % b == 0){
		return b;
	}
	if(b % a == 0){
		return a;
	}

	while(a != b){

		if(a > b){
				b = b;
				a = a-b;
		}else{

			a = a;
			b = b -a;
		}
	}

	return a;
}

bool khongNguyenToCungNhau(long int a, long int b){
	long int value = a;

	if(a % b == 0 || b % a == 0){
		return false;

	}
	if(a == b){

		return false;
	}
	if(a > b){
		value = b;
	}

	for (int i = 2; i <= sqrt(value); ++i){
		//cout << i << endl;
		if(a % i == 0 && b % i == 0){
			return false;
		}
	}

	return true;
}

bool divisble(vector<long int> a, vector<long int> b){

	// neu thang a chia het cho  b hoac con du thi tich day a, se lon hon day b
	
	long long tichA = 1;
	long long tichB = 1;

	long long uc;
	for (int i = 0; i < a.size(); ++i){

		if(a[i] == 1){
			continue;
		}

		for (int j = 0; j < b.size(); ++j){

			if(b[j] == 1){
				continue;
			}
			
			uc = ucln(a[i], b[j]);
			a[i] = a[i] / uc;
			b[j] = b[j] / uc;
			
		}
	}
	

	for (int i = 0; i < a.size(); ++i){
		//cout << "i:" << i << " " << a[i]<< ":" << b[i] << endl;
		tichA *= a[i];
		tichB *= b[i];
	}


return tichA > tichB;


}

void findSeq(){

	for (int i = 0; i < v.size(); ++i){

		seq.v.clear();
		seq.v.push_back(v[i]);

		for (int j = i+1; j < v.size(); ++j){
			if(khongNguyenToCungNhau(v[i], v[j])){
				// tiep tuc tim kiem
				seq.v.push_back(v[j]);
				
			}else{
				// bo qua j
				//continue;
			}
		}

		// kiem tra neu do dai lon hon 1 ta them vao

		if(seq.v.size() > 1){
			vSeq.push_back(seq);
		}
	}

	// ta kiem tra lai lan nua

	int maxLength = 0;
	int maxLengthIndex = -1;
	long long maxTong = 0;

	for (int i = 0; i < vSeq.size(); ++i){	
			seq = vSeq[i];

			if(seq.v.size() == maxLength){
				
				if(maxLengthIndex > -1 && divisble(vSeq[i].v, vSeq[maxLengthIndex].v)){
					// bo qua
					// nghia la tich day a > day b nen ta bo qua
					continue;
				}
			}

			if(seq.v.size() < maxLength){
				// bo qua

				continue;
			}

			maxLengthIndex = i;
			maxLength = seq.v.size();
		
	}

	if(maxLengthIndex > -1){

		seq = vSeq[maxLengthIndex];
		cout << maxLength;
		cout << endl;

		for (int i = 0; i < seq.v.size(); ++i){
			cout << seq.v[i];
			if(i < seq.v.size() -1 ){
				cout << " ";
			}
			
		}

	}else{
		cout << -1;
	}

}

int main(){
	

	int n;
	long int a;


	cin >> n;
	for (int i = 0; i < n; ++i){
			cin >> a;
			v.push_back(a);
	}

	findSeq();

	return 0;
}