#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> A;
vector<int> result;

void findSubSeq() 
{ 	

		int n = A.size();
		unordered_map<int, int> m; 
    int lis_size = 1; 
    int lis_index = 0; 
  
    m[A[0]] = 1; 
  
    for (int i = 1; i < n; i++) { 
        m[A[i]] = m[A[i] - 1] + 1; 
        if (lis_size < m[A[i]]) { 
            lis_size = m[A[i]]; 
            lis_index = A[i]; 
        } 
    } 
  	
  	int total = lis_size;
    int start = lis_index - lis_size + 1; 

    int index = 0;

    while (start <= lis_index) { 
    		if(index == 0 && start != 1){
    			total --;
    		}
    		if(start == lis_index && start != 1000){
    			total --;
    		}
        start++; 
        index++;
    } 

    cout << total;
} 


int main(){
	
	int n,a;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		A.push_back(a);
	}
	if(A.size() == 1){
		cout << 0;
	}else{
		findSubSeq();
	}
	
	return 0;
}