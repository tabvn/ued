#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("SVOI.INP");
ofstream fo ("SVOI.OUT");

struct BT{
	int a,b,c,d;
	bool isDone;
};

BT bt;
vector<BT> v;

int score = 0;
int doHomeWork(int t, int p){
	for (int i = 0; i < v.size(); ++i){
		bt = v[i];
		if(bt.isDone == true){
			continue;
		}
		if(t >= bt.a && p >= bt.b){
			// co kha nang giai dc bai nay
			score++;
			// tang them kien thuc 
			t += bt.c;
			p += bt.d;
			// danh dau bai nay da lam xong
			bt.isDone = true;
			v[i] = bt; // gan lai gia tri vao mang dung pointer thi ko can gan lai vector<BT*> bt;

			// neu giai dc bai nao thi tiep tuc giai
			doHomeWork(t,p);

		}

	}

	return score;
}
int main(){

	int n,t,p;
	int a,b,c,d;

	fi >> n >> t >> p;

	for (int i = 0; i < n; ++i){
		fi >> a >> b >> c >> d;
		bt.a = a;
		bt.b = b;
		bt.c = c;
		bt.d = d;
		bt.isDone = false; // mac dinh la bai tap chua giai dc

		v.push_back(bt);
	}	

	// write output to file
	fo << doHomeWork(t, p); 

	fi.close();
	fo.close();

	return 0;
}