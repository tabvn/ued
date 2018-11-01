#include <iostream> 
#include <vector>
using namespace std;

/*
S = 1/0! + 1/1! + 1/2! + ... 1/n!
mau chung se bang n!
ta tinh theo kieu quy dong len roi gian uoc dan dan
*/

struct PhanSo{
	int tu;
	vector<int> mau;
};

PhanSo p;

long long tinhMauSo(){
	long long v = 1;

	for (int i = 0; i < p.mau.size(); ++i){
		v *= p.mau[i];
	}

	return v;
}
void sum(int n){
	
	p.tu = 0;
	p.mau.clear();

	p.mau.push_back(1);

	for (int i = 0; i <=n; ++i){
		if( i == 0 || i == 1){
			p.tu += 1;	
			continue;
		}
		p.mau.push_back(i);
		p.tu = p.tu * i;
		p.tu = p.tu + 1;

		// tien hanh gian uoc

		for (int j = 0; j < p.mau.size(); ++j){
			// neu tu chia het cho so nao torng mau thi cu viec chia 
			
			if(p.tu % p.mau[j] == 0 && p.mau[j] != 1){
					// danh dau la da chia het va xoa
					int ketqua = p.tu / p.mau[j];
					p.mau[j] = 1; //
					p.tu =ketqua;
			}
		}

	}

	
}

// test
void display(){
	cout << "Tu so:" << p.tu;
	cout << "Mau so:" << endl;
	for (int i = 0; i < p.mau.size(); ++i){
		cout << p.mau[i] << " ";
	}
}

int main(){
	int n;
	cin >> n;
	sum(n);
	//display();
	cout << p.tu << "/"<< tinhMauSo();
	return 0;
}