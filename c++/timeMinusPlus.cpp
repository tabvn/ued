#include <iostream> 
using namespace std;

struct Time
{
	int h,m,s;
};

Time t1,t2;

int getSeconds(Time t){

	return (t.h * 3600) + (t.m * 60) + (t.s);
}

Time tru(Time a, Time b){
	// get number seconds of Time
	int aSeconds = getSeconds(a);
	int bSeconds = getSeconds(b);
	int seconds;
	// let check

	if(bSeconds > aSeconds){
		seconds = bSeconds - aSeconds;
	}else{
		seconds = aSeconds - bSeconds;
	}
	// convert sang Time

	Time c;

	// tinh gio
	c.h = seconds/3600;
	
	// giay con lai
	seconds = seconds - (c.h * 3600);
	// chia cho phut
	c.m = seconds/60;
	// giay con lai
	seconds = seconds - (c.m * 60);
	// giay
	c.s = seconds;

	return c;

}

Time cong(Time a, Time b){
	// cong giay 
	Time c;

	// reset mac dinh ve 0:0:0
	c.s = 0;
	c.m = 0;
	c.h = 0;

	// tien hanh cong giay
	c.s = a.s +b.s;
	if(c.s >=60){
		int increMinue = c.s/60;
		c.s = c.s - (increMinue * 60);
		// tang so phut
		c.m = c.m + increMinue;
	}
	// cong phut
	
	c.m = c.m + (a.m + b.m);

	if(c.m >= 60){
		int increasehour = c.m / 60;
		c.m = c.m - (60*increasehour);
		c.h = c.h + increasehour;
	}
	// hour
	c.h = c.h + a.h + b.h;
	if(c.h >=24){
		c.h = c.h - ((c.h/24) * 24);
	}

	return c;

}
int main(){

	t1.h = 12;
	t1.m = 59;
	t1.s = 30;

	t2.h = 15;
	t2.m = 0;
	t2.s = 30;

	Time s;
	// tinh t1 + t2
	s = cong(t1, t2);
	cout << t1.h <<":" << t1.m<< ":" << t1.s<< " + " << t2.h <<":" << t2.m<< ":" << t2.s << " = ";
	cout << s.h <<":" << s.m<< ":" << s.s << endl;

	// t1 - t2;
	s = tru(t1, t2);
	cout << t1.h <<":" << t1.m<< ":" << t1.s<< " - " << t2.h <<":" << t2.m<< ":" << t2.s<< " = ";
	cout << s.h <<":" << s.m<< ":" << s.s;
	
	return 0;
}