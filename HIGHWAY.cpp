#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fi ("HIGHWAY.INP");
ofstream fo ("HIGHWAY.OUT");

struct Traffic
{
	long long a,b;
	long long value;

};

vector<Traffic> v;
vector<long long> nums;

Traffic traffic;

long long getTrafficValue(long a, long b){
	long long value = a - b;
	if(value < 0){
		return 0 - value;
	}
	return value;
}

bool ascSort(Traffic a, Traffic b){
	return a.value < b.value;
}

int main(){
	int n;
	long long x;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> x;
		nums.push_back(x);
	}
	//12 4 6 9 7 14
	long int inc = 0;
	while(inc < (int) (nums.size() -1)){
		//cout << nums[inc] << " " << nums[inc+1] << endl;
		traffic.a = nums[inc];
		traffic.b = nums[inc+1];
		traffic.value = getTrafficValue(traffic.a, traffic.b);

		v.push_back(traffic);

		inc++;
	}


	sort(v.begin(), v.end(), ascSort);

	long long minValue = 0;
	long long tmpValue;

	for (int i = 0; i < (int) v.size() -1; ++i){
		tmpValue = v[i+1].value - v[i].value;
		if(minValue ==0){
			minValue = tmpValue;
		}
		if(tmpValue < minValue && tmpValue != 0){
			minValue = tmpValue;
		}
	}

	fo << minValue;



	fi.close();
	fo.close();

	return 0;
}