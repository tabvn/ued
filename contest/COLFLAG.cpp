#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> v1;

struct Color
{
	int value;
	int total;
};

struct Flag
{

		vector<Color> colors;
		int  findColorIndex(int n){
			
			for (int i = 0; i < this->colors.size(); ++i){
				if(this->colors[i].value == n){
					return i;
				}
			}

			return -1;
		}

		void add(int n){

			int colorIndex = findColorIndex(n);
			if(colorIndex == -1){
				// not exist

				Color c;
				c.value = n;
				c.total = 1;
				this->colors.push_back(c);

			}else{

				this->colors[colorIndex].total = this->colors[colorIndex].total +1;
			}

		}
};


Flag f;

Flag f1;


bool ascSort(Color a , Color b){
	return a.total < b.total;
}

bool descSort(Color a , Color b){
	return a.total > b.total;
}

int main(){
	
	int n,m,a;

	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		cin >> a;
		v.push_back(a);
		f.add(a);

	}

	sort(f.colors.begin(), f.colors.end(), ascSort);


	for (int i = 0; i < m; ++i){
		cin >> a;
		v1.push_back(a);

		f1.add(a);
	}

	sort(f1.colors.begin(), f1.colors.end(), descSort);

	for (int i = 0; i < f1.colors.size(); ++i){
		

		for (int j = 0; j < f.colors.size(); ++j){

			if(f1.colors[i].total == 0){
				break;
			}
			if (f.colors[j].total == 0){
				continue;
			}

			f1.colors[i].total --;
			f.colors[j].total --;





		}
	}

	int total = 0;

	for (int i = 0; i < f.colors.size(); ++i){
		//cout << "f:" << f.colors[i].value << " total:" << f.colors[i].total << endl;
		if(f.colors[i].total > 0){
			total ++;
		}
	}

	cout << total;


	return 0;
}