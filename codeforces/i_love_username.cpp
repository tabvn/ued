#include <iostream> 
using namespace std;

int main(){
	
	int n, score, maxScore = 0, minScore = 10000, amp = 0;
	cin >>n;

	if(n == 1){
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i){
		cin >> score;

		if(score > maxScore || score < minScore){
			if(i != 0){
				amp ++;
			}
			
		}
		if(score < minScore){
			minScore = score;
		}
		if(score > maxScore){
			maxScore = score;
		}
		
	}

	if(amp == n){
		amp--;
	}

	cout << amp;

	return 0;
}