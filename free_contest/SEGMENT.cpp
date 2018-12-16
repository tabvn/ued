#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


struct Line
{
	long int a,b;
	long long length;
	Line(long int a, long int b){
		this->a = a;
		this->b = b;
		this->length = b - a;
	}

};

vector<Line*> v;

void addLine(long int a, long int b){
	Line *l = new Line(a, b);
	v.push_back(l);
}

int findIndexStart(long int a){

	int index = -1;

	long int maxLength = -1;

	for (int i = 0; i < v.size(); ++i){
		if(v[i]->a > a){
			break;
		}
		if(v[i]->a <= a){
			if(v[i]->length > maxLength){
				index = i;
			}
		}
	}
	return index;
}

int findIndexEnd(long int b){

	int index = -1;
	long int maxLength = -1;

	for (int i = (int)v.size() -1; i >=0; --i){
		
		if(v[i]->b < b){

			break;
		}

		if(v[i]->b >= b){
				if(v[i]->length > maxLength){
					index = i;
				}
		}
	}

	return index;
}

void answer(long int a, long int b){

	int n = 0;

	int startIndex = findIndexStart(a);
	int endIndex = findIndexEnd(b);
	long long sum = 0;

	long int start;
	long int end;

	if (startIndex == -1 || endIndex == -1){
		cout << -1;
	}else{

		if(startIndex == endIndex){
			cout << 1;
		}else{
			// tinhj tiep
			if((v[endIndex]->b - v[endIndex]->a) + (v[startIndex]->b - v[startIndex]->a) >= (b - a)){
				cout << 2;
				cout << endl;
				return;
			}

			start = v[startIndex]->b;
			end = v[endIndex]->a;
			n = 2;
			while(end > start){

					int maxL = -1;
					int theIndex = -1;

					for (int i = 0; i < endIndex; ++i){
						if(v[i]->b <= end){
							if(v[i]->length > maxL){
								theIndex = i;
							}
						}
					}

					//cout << "theIndex:" << theIndex;
					if(theIndex != -1){
						end = v[theIndex]->a;
						n++;
					}

					
			}
			cout << n;
		}
	}

	cout << endl;
}

bool ascSort(Line *a, Line *b){
	return a->a < b->a;
}

int main(int argc, char const *argv[]){
	

	int n,q;
	long int a, b;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a >> b;
		addLine(a, b);
	}

	cin >> q;

	sort(v.begin(), v.end(), ascSort);

	for (int i = 0; i < q; ++i){
		cin >> a >> b;
		answer(a, b);

	}



	return 0;
}