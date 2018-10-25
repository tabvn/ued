#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fi ("XYZ.INP");
ofstream fo ("XYZ.OUT");


struct Time{
	int h,m,s;
};

struct Call{
	string from;
	string to;
	Time start;
	Time end;

};

struct People{
	string number;
	long long score;
};

vector<Call> callArr;
vector<People> peopleArr;

Call call;
People p;
Time t;

int charToInt(char c){
	switch (c){

		case '0':
			return 0;

		case '1':
			return 1;

		case '2':
			return 2;

		case '3':
			return 3;

		case '4':
			return 4;

		case '5':
			return 5;

	  case '6':
			return 6;

		case '7':
			return 7;

		case '8':
			return 8;

		case '9':
			return 9;		

		default: 

			return 0;


	}
}


int findPeopleIndex(string phoneNumber){

	for (int i = 0; i < peopleArr.size(); ++i){
		if(phoneNumber == peopleArr[i].number){
			return i;
		}
	}

	return -1;

}


// tinh diem cuoc goi den , hoac nhan cuoc goi

void AddScore(string phoneNumber, int second, bool caller){

	int score = second;

	if(caller){
		// ta nhan doi 
			score = second*2;
	}

	int pIndex = findPeopleIndex(phoneNumber);

	peopleArr[pIndex].score = peopleArr[pIndex].score + score;



}


int getSecond(string s){
	int second = 0;
	for (int i = 4; i <= 5; ++i){
		if(i == 4){
			second += charToInt(s[i]) * 10;
		}else{
			second += charToInt(s[i]);
		}
	}

	return second;
}
int getMinue(string s){
	int second = 0;
	for (int i = 2; i <= 3; ++i){
		if(i == 2){
			second += charToInt(s[i]) * 10;
		}else{
			second += charToInt(s[i]);
		}
	}

	return second;
}

int getHour(string s){
	int second = 0;
	for (int i = 0; i <= 1; ++i){
		if(i == 0){
			second += charToInt(s[i]) * 10;
		}else{
			second += charToInt(s[i]);
		}
	}

	return second;
}

Time getTime(string s){
	t.h = getHour(s);
	t.m = getMinue(s);
	t.s = getSecond(s);

	return t;
}

int getSecondRange(Call c){

	int h = c.end.h - c.start.h;
	int m = c.end.m - c.start.m;
	int s = c.end.s - c.start.s;

	int totalSeconds = h*3600 + m*60 + s;

	return totalSeconds;
}

void addPeople(string phoneNumber){
	int pIndex = findPeopleIndex(phoneNumber);
	if(pIndex == -1){
		// chi them vao nguoi chua tung them truoc do
		p.number = phoneNumber;
		p.score = 0;
		peopleArr.push_back(p);
	}
}

int calculateSecond(string start, string end){

	int total = 0;

	return total;
}

int main(){

	int n;

	string from; // thuc hien cuoc goi
	string to; // nhan cuoc goi
	string start; // thoi gian bat dau
	string end; // thoi gian ket thuc

	fi >> n;

	for (int i = 0; i < n; ++i){
			fi >> from >> to >> start >> end;
			call.from = from;
			call.to = to;
			call.start = getTime(start);
			call.end = getTime(end);

			// them cuoc goi vao list
			callArr.push_back(call);

			// nhan dc cuoc goi hay thuc hien cuoc goi ta deu them vao danh sach
			addPeople(from);
			addPeople(to);

	}

	// phan tinh toan va thong ke
	for (int i = 0; i < callArr.size(); ++i){
			call = callArr[i];
			AddScore(call.from, getSecondRange(call), true);
			AddScore(call.to, getSecondRange(call), false);
	}

	// sau khi add score ta di tim nguoi co diem nhieu nhat
	long long max = 0;
	for (int i = 0; i < peopleArr.size(); ++i){
			if(peopleArr[i].score > max){
				max = peopleArr[i].score;
			}
	}

	fo << max;

	fi.close();
	fo.close();

	return 0;
}