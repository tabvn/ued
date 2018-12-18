#include <iostream>
#include <vector>
using namespace std;

struct Hat
{
	int value;
	int total;

	Hat(){
		this->total = 0;
	}
	
};
struct Party
{
	std::vector<Hat> v;


	int findIndex(int n){
		for (int i = 0; i < this->v.size(); ++i){
			if(this->v[i].value == n){
				return i;
			}
		}

		return -1;
	}

	void add(int n){
		int index = this->findIndex(n);
		if(index == -1){
			Hat h;
			h.total = 1;
			h.value = n;
			this->v.push_back(h);


		}else{
			this->v[index].total++;
		}

	}

	bool isPosible(int n){
		
		int i = 0;
		int j = this->v.size();

		while(i <= j){

			if(this->v[i].value != n && this->v[i].total == n){
				return true;
				
			}
			if(this->v[j].value != n && this->v[j].total == n){
				return true;
				
			}
			i++;
			j--;
		}
		
		

		if(n == 0 && this->v.size() == 1){
			return true;
		}

		return false;

	}
};

Party p;


vector<int> v;


int main(int argc, char const *argv[]){
	
	int n,a;

	cin >> n;
	if(n == 1){
		cout << "Possible";
		return 0;
	}

	for (int i = 0; i < n; ++i){
		cin >> a;

		p.add(a);
		v.push_back(a);
	}

	bool isPosible = true;

	for (int i = 0; i < p.v.size(); ++i){
		if (!p.isPosible(p.v[i].value)){
			isPosible = false;
			break;
		}

	}

	if(!isPosible){
		cout << "Impossible";
	}else{
		cout << "Possible" << endl;
		for (int i = 0; i < p.v.size(); ++i){
			for (int j = 0; j < p.v[i].total; ++j){
				cout << (i+1) << " ";
			}
		}
	}

	return 0;
}