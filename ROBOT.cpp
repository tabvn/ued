#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
/Users/toan/ued/18-10-2018
*/

ifstream fi ("ROBOT.INP");
ofstream fo ("ROBOT.OUT");


// Cac Bo Test

struct Test
{
	int k;
	long int n,a,b;
	vector<long long> v;
};

vector<Test> testArr;
Test test;


// kiem tra xem diem nay da di qua hay chua

bool pointIsDone(vector<long long> v, long long point){

	for (int i = 0; i < v.size(); ++i){
		if(v[i] == point){

			return true;
		}
	}
	return false;
}



long long findNextPoint(Test t, long long currentPoint, bool left, long long total){

	long long nextPoint;
	if(t.k == 0){
		return total;
	}
	if(left){
		nextPoint = currentPoint - t.b;
		if( nextPoint >= 1 && !pointIsDone(t.v, nextPoint)){
				total++;
		}

	}else{
		nextPoint = t.a + currentPoint;
		if(nextPoint <= t.n && !pointIsDone(t.v,nextPoint)){
			total++;
		}
	}

	t.k = t.k --;

	return findNextPoint(t, nextPoint, left, total);
}

long long go(Test t, long long currentPoint, bool goLeft){	
		// di thang
		long long nextPoint;

		//cout << "current:" << currentPoint << " trai:" << goLeft << endl;

		// kiem tra neu het luot di thi tra ve
		if(t.k == 0 || t.v.size() == t.n){
			return t.n - t.v.size(); // tong so diem tru du so diem da di qua 
		}

		if(goLeft == false){

			nextPoint = t.a + currentPoint;

			if(nextPoint > t.n){
				// vuot qua thi chi dc phep quay lai
				goLeft = true;

			}else{
				// ta kiem tra xem diem nay da di qua chua
				if(!pointIsDone(t.v, nextPoint)){
					currentPoint = nextPoint;
					// chua di qua thi ta them vao
					t.v.push_back(currentPoint);
				}else{
					// diem di toi da di roi, ta kiem tra so lan k o diem nguoc lai neu co thi di
					if(findNextPoint(t, currentPoint, !goLeft, 0)){
						goLeft = !goLeft;
					}
					
				}

				// tang them mot luot di k

				t.k --;
			}
		}else{
			// di lui
				nextPoint = currentPoint - t.b;

				if(nextPoint < 1){
					// nam ngoai doan dang xet
					// go right
					goLeft = false;
				}else{
					// kiem tra xem neu next point chua add thi them vao
					if(!pointIsDone(t.v, nextPoint)){
						t.v.push_back(nextPoint);
					}
					else{
						// diem lui da di roi, ta thu kiem tra xem diem nguoc lai sau 1 lan buoc neu co thi ta quay lai
						if(findNextPoint(t, currentPoint, !goLeft, 0)){
							goLeft = !goLeft;
						}
					}

					t.k --;
				}
		}
		// tiep tuc go
		return go(t, nextPoint, goLeft);
}

void robot(){

	long long startPoint;

	for (int i = 0; i < testArr.size(); ++i){

		startPoint = 1; // diem bat dau
		testArr[i].v.push_back(startPoint);

		fo << go(testArr[i], startPoint, false); // khoi dau di toi

		if(i < testArr.size() -1){
			fo << endl;
		}
	}
}

int main(){

	int t; // so bo test
	long long n,a,b,k;

	fi >> t;

	for (int i = 0; i < t; ++i){
		fi >> n >> a >> b >> k;
		test.a = a;
		test.b = b;
		test.n = n;
		test.k = k;
		testArr.push_back(test);
	}


	robot();



	fi.close();
	fo.close();
	return 0;
}