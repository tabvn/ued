#include <iostream>
#include <vector>

using namespace std;


struct Max{
	long long n1;
	int i1;
	long long n2;
	int i2;
	long long total;
};

vector<long long> v;
Max m;


int main(){

	int n;
	long long a;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
	}


	long long total = 0;
	long long t1 = 0;
	long long t2 = 0;
	long long currentTotal = 0;

	m.i1 = -1;
	m.i2 = -1;

	if(v.size() == 1){
		m.i1 = 0;
		m.n1 = v[0];
	}

	for (int i = 0; i < v.size(); ++i){
		t1 = v[i]*i;

		for (int j = i+1; j < v.size(); ++j){
			t2 = v[j] * j;
			currentTotal = t1+t2;
			if(currentTotal > total){

				total = currentTotal;
				m.i1 = i;
				m.i2 = j;
				m.n1 = v[i];
				m.n2 = v[j];
				m.total = total;


			}
			if(currentTotal == total){
				if(v[j] < m.n2){

					total = currentTotal;
					m.i1 = i;
					m.i2 = j;
					m.n1 = v[i];
					m.n2 = v[j];
					m.total = total;
				
				}
			}
		}
	}

	if(m.n1 > m.n2){
			cout << m.n2 << " " << m.i2 << " " << m.n1 << " " << m.i1 << " " << m.total;
  }else{
  	cout << m.n1 << " " << m.i1 << " " << m.n2 << " " << m.i2 << " " << m.total;
  }

	return 0;

}