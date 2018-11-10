#include <iostream> 
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("/Users/toan/ued/BOT.INP");
ofstream fo ("/Users/toan/ued/BOT.OUT");

vector<long int> v;

int main(){
	
	int n;
	long int ai;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> ai;
		v.push_back(ai);
	}

	int startIndex = -1;
	int endIndex = -1;
	startIndex = 0;

	long long maxValue = 0;

	for (int i = 0; i < v.size(); ++i){

			bool isIgnore = false;

			long long subValue = v[i];
			int theIndex = 0;
			for (int j = i; j < v.size(); ++j){

				if(subValue + v[j+1] < 0){
					
					isIgnore = true;
					break;
				}else{
					theIndex = j;
					cout << "total:" << subValue <<  " plus: " << j << " :" << v[j] << endl;
					subValue += v[j];
				}

			}

			

			
			cout << "is igored:" << isIgnore << " i:"<< i << " sub:" << subValue<< endl;
			if(subValue > maxValue){

				startIndex = i;
				maxValue = subValue;
				endIndex = theIndex;

			}
			subValue = 0;
			
	}

	cout << startIndex << " " << endIndex << " " << maxValue;

	fi.close();
	fo.close();

	return 0;

}