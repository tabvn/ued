#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool ascSort(int a, int b){
	return  a < b;
}

void removeZeroLeading(){

	vector<int> zeroArr;

	int secondIndex = 0;
	int tmp;

	for (int i = 0; i < v.size(); ++i){
		if(v[i] == 0){
			zeroArr.push_back(i);
		}
		if(v[i] != 0){
			secondIndex = i;
			break;
		}
	}

	for (int i = 0; i < zeroArr.size(); ++i){
			tmp = v[secondIndex];
			v[secondIndex] = 0;
			v[zeroArr[i]] = tmp;
			secondIndex++;
	}

}
void solveProblem(int problemCase){

		sort(v.begin(), v.end(), ascSort);

		removeZeroLeading();
		 
    long long a = 0, b = 0; 
    for (int i = 0; i < v.size(); i++) 
    { 
      if (i %2 ==0) {
      	a = a*10 + v[i]; 
      }   
      else{
      	b = b*10 + v[i]; 
      }
           
    } 
  
    // return the sum 
   cout << "Case #" << problemCase << ": "<<(a+b) << endl;
}


int main(){
	int t,n, digit;
	cin >> t;
	
	for (int i = 0; i < t; ++i){
		cin >> n;
		v.clear();
		for (int j = 0; j < n; ++j){
			cin >> digit;
			v.push_back(digit);
		}
		solveProblem(i+1);
	}
	return 0;
}