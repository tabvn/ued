#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

bool ascSort(int a , int b){
	return a < b;
}

int main(int argc, char const *argv[]){
	
	int n,a;

	cin >> n;

	int total = 0;

	for (int i = 0; i < n; ++i){
		cin >> a;
		if(a == 4){
			total ++;

		}else{
			v.push_back(a);
		}
	}

	if(v.size() == 0){
		cout << total;
		return 0;
	}

	sort(v.begin(),v.end(), ascSort);

	int carry = v[0];
	total ++;

	for (int i = 1; i < v.size(); ++i){
			if(v[i] == 0){
				continue;
			}

			if(carry == 4){
				total ++;
				carry = 0;
			}
			

			if(v[i] == 1){

					int index = -1; 
					for (int j = i+1; j < v.size(); ++j){
						if(v[j] == 0){
							continue;
						}
						if(v[j] == 3){
							index = j;
							break;

						}
					}

					if(index != -1){
		
						carry += v[index];
						v[index] = 0;
					}else{
						carry += v[i];
					}

			}
			else if(v[i] == 2){

					int index = -1; 
					for (int j = i+1; j < v.size(); ++j){
						if(v[j] == 0){
							continue;
						}
						if(v[j] == 2){
							index = j;
							break;

						}
					}

					if(index != -1){
						carry += v[index];
						v[index] = 0;
						
					}else{
						carry += v[i];
					}

			}else{
				carry += v[i];
			}

			
			if(carry >4){
				carry = v[i];
				total++;
			}
			if(carry == 4){
				carry = 0;
				total ++;
			}
		
	}


	cout << total;

	return 0;
}