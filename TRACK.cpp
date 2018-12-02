#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fi ("TRACK.INP");
ofstream fo ("TRACK.OUT");

vector<long long> v;



/*
// cach khong hieu qua
void fn(int t){

	long long total = 0;
	long long sum = 0;
	for (long long i = 0; i < v.size(); ++i){
		if(v[i] > t){
			continue;
		}else{
			total++;
		}

		sum = v[i];

		for (int j = i+1; j < v.size(); ++j){
			sum += v[j];

			if(sum > t){
				// qua suc xu ly tan rac
				break;

			}else{
				total++;
			}
		}
	
		// kiem tra lai tong tan rac neu vuot qua ta bo qua 
		if(sum > t){
			continue;
		}

	}

	cout << total;
	fo << total;
}
*/


// giai phap tot hon

long long fn(long long t){
		int start,end;

		long long count = 0;
		long long sum = v[0]; 
		int n = (int) v.size();

		start = 0;
		end = 0;

		while (end < n)  
		{ 
			// neu tong <= tan rac thi tiep tuc di toi va cap nhat count va tong
			if (sum <= t)  
			{ 
			    end++; 
			    count += end - start; 
			    if (end < n){
			    	 sum += v[end]; 
			    } 
			   
			} 
			else 
			{ 
				// neu tong ma lon hon Tan rac thi tru di sum va dong thoi tang vi tri bat dau dem len
			    sum -= v[start]; 
			    start++; 
			} 
		} 

		return count; 
}

int main(){

	long long n,t,x;
	fi >> n >> t;
	for (long long i = 0; i < n; ++i){
		fi>>x;
		v.push_back(x);
	}

	fo << fn(t);


	fi.close();
	fo.close();

	return 0;
}
