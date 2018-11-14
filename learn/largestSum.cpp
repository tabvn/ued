#include <climits>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int findLargestSub(){
    
    int start, end;
    int maxSoFar = INT_MIN;
    int maxEnd = 0;
    for(int i = 0; i< v.size(); i++){
        maxEnd += v[i];
        
        
        if(maxEnd > maxSoFar){
            maxSoFar = maxEnd;
        }
        if(maxEnd < 0){
            maxEnd = 0;
        }
    }
    
    return maxSoFar;
}
int main() {
    
	//code
	int t,n, ai;
    cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n;
    	v.clear();
    	for(int j = 0; j < n; j++){
    	    cin >> ai;
    	    v.push_back(ai);
    	}
    	cout << findLargestSub() << endl;
	}
	return 0;
}