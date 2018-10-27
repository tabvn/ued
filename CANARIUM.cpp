#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("CANARIUM.INP");
ofstream fo ("CANARIUM.OUT");

int t;
long long n;
float m;
long long k; // so k

vector<long long> v;

void canarium(){
	/*
	goi n la là số hình chư nhật đếm theo hàng ngang
	m là số hình chữ nhật đếm theo hàng dọc
	[[2(n-1) + 1] * (m-1)] + n = tram*2;
	=> (2n-1)*(m-1) + n = tram*2
	dieu kien la n >= m >= 1
	=> m = (tram*2 + n -1)/(2n-1)
	*/
	for (int i = 0; i < v.size(); ++i){
		k = v[i];
		n = 1;
		m = k;

		while(n<k*2){
			m = float(k*2 + n -1)/(2*n -1);

			if(n >= m && (long int)m == m ){
				break;
			}
			n++;
		}

		if(m < n && (long int)m == m){
			// chi tinh sô đường hàng ngang or dọc , ko tính ô chữ nhật nên ta -1
			fo << (int)(m -1) << " " << n -1 << endl;
			
		}else{
			fo << -1 << " " << -1 << endl;
		}
	
	}

}

int main(){
	
	fi >> t;

	for (int i = 0; i < t; ++i){
		fi >> k;
		v.push_back(k);
	}

	
	canarium();
	

	fi.close();
	fo.close();

	return 0;
}