#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fi ("GOMIN.INP");
ofstream fo ("GOMIN.OUT");

int timerIndex = -1;
int t;
int timerLeft;
bool isSolveTimerBoom = false;
// Boom
struct Boom
{
	int x;
	int index;
	bool done;
	bool isTimer;
};


vector<Boom> boomArr;
vector<Boom> startArr;

Boom boom;

/*
* Tinh độ dài 2 vị trí quả boom
*/
int lenTwoPoint(int x1, int x2){

	int sum = 0;

	if(x1 > x2){
		sum =  x1 - x2;
	}else{
		sum = x2 -x1;
	}

	if(sum < 0){
		sum = 0 - sum;
	}
	return sum;
}


// tim cac diem khoi dau de go boom
void findStarts(){

	for (int i = 0; i < boomArr.size(); ++i){
			if(lenTwoPoint(boomArr[i].x, boomArr[timerIndex].x) < t){
				startArr.push_back(boomArr[i]);
			}
	}
}


bool isDone(){
	for (int i = 0; i < boomArr.size(); ++i){
		if(boomArr[i].done == false){
			return false;
		}
	}

	return true;
}

int go(Boom currentBoom, bool left, int len){



	//cout << "current:" << currentBoom.x << " len:" << len << " left" << left  << " fixed" << boomArr[currentBoom.index].done << endl;

	// di sang trai

	if(isDone()){
		return len;
	}

	if(left == true && currentBoom.index == 0){
			left = false;
	}
	if(left == false && currentBoom.index == boomArr.size() -1){
		left = true;
	}


	int i;

	if(left){

		//int i = currentBoom.index -1;
		for (int j = currentBoom.index - 1; j >= 0 ; --j){
			if(boomArr[j].done == false){
				i = j;
				break;
			}
		}

	}else{

		for (int j = currentBoom.index + 1; j < boomArr.size() ; ++j){
			if(boomArr[j].done == false){
				i = j;

				break;
			}
		}
	}

		// kiem tra neu quay lai ko kip thi ta phai quay lai go qua bom hen gio
		int timeLeft = 1;
		int lenPoint = lenTwoPoint(currentBoom.x, boomArr[i].x);;
		if(isSolveTimerBoom == false){

			timeLeft = timerLeft = lenPoint;
			int lenBackToTimer = lenTwoPoint(boomArr[i].x, boomArr[timerIndex].x);
			timerLeft -= lenBackToTimer;
		}
		
		if(!isSolveTimerBoom && timerLeft <= 0){

			// qua bom hen gio van con va kha nay quay laij ko kip, nên ta phai quay lại vị trí qua bom hen gio va fix no
			lenPoint = lenTwoPoint(currentBoom.x, boomArr[timerIndex].x);
			len += lenPoint;

			isSolveTimerBoom = true;
			boomArr[timerIndex].done = true;
			currentBoom = boomArr[timerIndex];
			
		}else{
			len += lenPoint;
			timerLeft -= lenPoint;
			boomArr[i].done = true;
			currentBoom = boomArr[i];


		}

		return  go(currentBoom, left, len);
}


/*
đánh dấu các quả boom chưa dc gỡ.
*/
void clearDone(){
	for (int i = 0; i < boomArr.size(); ++i){
		boomArr[i].done = false;
	}
}


/*
Tim thoi gian ngan nhat de go bom
*/
int findMinTime(){
	
	Boom b;
	bool goLeft = true;

	int minLen = -1;

	for (int i = 0; i < startArr.size(); ++i){

		clearDone();
		timerLeft = t; // reset lai thoi gian neu chon diem bat dau khac nhau

	
		b = startArr[i];
		// gia su  di ve ben trai
		if(b.isTimer == true){
			// qua dau tien la qua bom hen gio
			isSolveTimerBoom = true;
		}
	

		boomArr[b.index].done = true;
		b.done = true;

		// de ve ben trai
		int len = go(b, true, 0);

		if(minLen == -1){
			minLen = len;
		}
		if(len < minLen){
			minLen = len;
		}


		// cho di ve phia ben phai
		clearDone();

		boomArr[b.index].done = true;
		b.done = true;

		timerLeft = t; // reset lai thoi gian neu chon diem bat dau khac nhau
		len = go(b, false, 0);

		if(len < minLen){
			minLen = len;
		}


	}


	return minLen;

}

int main(){


	int n,k,x;

	fi >> n >> t;

	timerLeft = t; // thời gian còn lại bằng k;

	for(int i = 0; i<n; i++){

		fi >> x;
		boom.x = x;
		boom.index = i;
		boom.done = false;
		boom.isTimer = false;
		boomArr.push_back(boom);

	}

	fi >> k;
	// index of timer boom is k -1
	timerIndex = k-1;
	boomArr[timerIndex].isTimer = true;

	// tim diem bat dau de go qua bom dau tien
	findStarts();

	fo << findMinTime();


	fi.close();
	fo.close();
	return 0;
}