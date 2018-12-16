#include <iostream> 
#include <math.h>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
const double X = (3+sqrt(6)); //5.44949;
vector<char> v;

void test(long long n){
	for (int i = 1; i < 40; ++i){
		cout << i << " :";
			cout << fixed <<  pow((3+sqrt(6)),i) << endl;
	}

}
int main(){
	ostringstream ss;
	string s;
	
	long long n;
	cin >> n;
	double value = pow(X, n);
	ss << fixed << value;
	s = ss.str();
	
	int indexOfComma = -1;

	for (int i = 0; i < s.size(); ++i){
		if(s[i] == '.'){
			// gap dau . thi dung
			indexOfComma = i;
			break;
		}
	
	}

	int count = 0;

	for (int i = indexOfComma -1; i >=0; --i){
		if(count >= 3){
			break;
		}

		v.push_back(s[i]);
		count ++;
	}
	
	if(v.size() < 3){
		cout  << 0;
	}
	for (int i = v.size()-1; i >=0; --i){
		cout << v[i];
	}

	return 0;
}