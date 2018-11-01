#include <iostream> 
#include <vector>
#include <fstream>

using namespace std;

ifstream fi ("RECOVERY.INP");
ofstream fo ("RECOVERY.OUT");

vector<int> v;


bool doubleCheck = false;

void updateArr(){
	
	vector<int> tmp;


	for (int i = 0; i < v.size(); ++i){
		if(v[i] != -1){
			tmp.push_back(v[i]);
		}
	}
	v.clear();

	for (int i = 0; i < tmp.size(); ++i){
		v.push_back(tmp[i]);
	}

	tmp.clear();

}

int total = 0;


int xoa(){

	
	int maxIndex = v.size() -1;

	for (int i = 0; i < v.size(); ++i){

		int nextIndex = i+1;
		if(nextIndex > maxIndex){
			break;
		}

		if(v[i] > v[nextIndex]){
				if(nextIndex +1 > maxIndex){
					// so tiep theo nua ko con thi ta xoa so hien tai
					v[nextIndex] = -1;

					updateArr();

					total ++;
				}else{
					// ta kiem tra do chenh lech
					int khoangCach1 = v[nextIndex+1] - v[i];
					int khoangCach2 = v[nextIndex +1] - v[nextIndex];
					if(khoangCach2 < 0){
						v[nextIndex] = -1;
						total ++;
						// ta cho kiem tra lai tu dau
					}
					if(khoangCach1 < 0){
						// xoa 
						v[i] = -1;
						total ++;
						updateArr();


					}else{

							// kiem tra khoang cach nao lon hon thi xoa
						if(khoangCach1 > khoangCach2){
							v[i] = -1;
							total++;
							updateArr();
						}else{
							v[nextIndex] = -1;
							total++;
							updateArr();
						}
					}
				
				}
		}
	}

	// kiem tra lai phan tu dau tien
	if(v.size() > 1){
		if(v[0] > v[1]){
			v[0] = -1;
			total += 1;
		}
	}

	if(doubleCheck){
		return total;
	}

	doubleCheck = true;

	return xoa();

}
int main(){
	int n, a;

	fi >> n;
	for (int i = 0; i < n; ++i){
		fi >> a;
		v.push_back(a);
	}

	fo << xoa();

	fi.close();
	fo.close();

	return 0;
}