#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("/Users/toan/ued/SEQ.INP");
ofstream fo ("/Users/toan/ued/SEQ.OUT");


vector<long int> v;

// tinh tong index -> index
long long sum(int start, int len){

	long long s = 0;

	int to = start + len;

	if(to > v.size()){
		to = v.size();
	}
	for (int i = start; i < to; ++i){
		//cout << v[i] << " ";
		s+= v[i];
	}


	return s;

}

long long sumWithB(long long aSum, int lastIndex){
	
	long long value = 0;

	int len = 3;


	long long maxValue = 0;
	long long theSumTotal = 0;

	int startIndex = lastIndex;

	while(startIndex < v.size() && len <= v.size()){
		if(startIndex == v.size() - 1){
			len += 3;
			startIndex = lastIndex;
		}

		if(startIndex + len <= v.size() && (startIndex +len) %3 ==0){
			
			long long bSum = sum(startIndex, len);
			
		

			theSumTotal = aSum+bSum;
			if(theSumTotal > maxValue){
				maxValue = theSumTotal;
			}
		}
		

		startIndex++;
	}

	return maxValue;

}

int main(){
	long int a;
	long long n;
	fi >> n;

	for (int i = 0; i < n; ++i){
		fi >> a;
		
		v.push_back(a);
	}

	int startIndex = 0;
	int len = 3;
	long long maxValue = 0;

	while(startIndex < v.size() && len <= v.size()){
		if(startIndex == v.size() - 1){
			len += 3;
			startIndex = 0;
		}
		
		if(startIndex + len <= v.size() && (startIndex +len %3) == 0){

			//cout << "Choui A:";
			long long aSum = sum(startIndex, len);

			//cout  << "=" << aSum <<  " index:" << startIndex << " len:" << len<< endl;
			// ta lan luot tang len roi kiem tra voi chuoi b

			int bStartIndex = startIndex + len;

			long long sWithB = sumWithB(aSum, bStartIndex);

			if(sWithB > maxValue){
				maxValue  = sWithB;
			}

		}
		
		startIndex ++;

		
	}

	fo << maxValue;

	return 0;
}