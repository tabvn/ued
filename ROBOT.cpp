#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
/Users/toan/ued/18-10-2018
*/

ifstream fi ("ROBOT.INP");
ofstream fo ("ROBOT.OUT");

struct Node
{
	int k;
	long int n,a,b;
	
};


vector<Node> v;

Node node;

vector<long int> p; // points

int main(){

	int t,k;
	long int n, a, b, current, addWith;

	fi >> t;

	for (int i = 0; i < t; ++i){
		fi >> n >> a >> b >> k;
		node.a = a;
		node.b = b;
		node.n = n;
		node.k = k;
		v.push_back(node);
	}

	for (int i = 0; i < v.size(); ++i){
		p.clear();
		node = v[i];
		a = node.a;
		b = node.b;
		n = node.n;
		k = node.k;

		addWith = a;
		current = 1;

		int inc = 0;

		p.push_back(current);

		while(inc < k){

			if(current + addWith > n){
				addWith = -b;
			}
			else if(current + addWith < 1){
				addWith = a;

			}else{

				inc++;
				current += addWith;
				bool exist = false;

				for (int n = 0; n < p.size(); ++n)
				{
					if(p[n] == current){
						exist = true;
						break;
					}
				}
				if(!exist){
					p.push_back(current); // kiem tra cac so da them neu trung thi thoi
				}
				
			}

		

		} 

		fo << (n - int(p.size())) << endl;
		


	}


	fi.close();
	fo.close();
	return 0;
}