#include <iostream> 
#include <vector>
using namespace std;

const int PASSENGER = 0;
const int SEAT = 1;
const int FLOOR = 2;

const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 3;
const int TOP = 4;


struct Node
{
	int nodeType;
	int row;
	int column;
};

struct Line
{
	vector<Node*> v;
	int len;
};

struct Point{
	int row;
	int column;
};
// array chua cac nodes

vector<Node> v;

void addNode(int row, int column, int nodeType){
	Node node;
	node.nodeType = nodeType;
	node.row = row;
	node.column = column;

	v.push_back(node);
}

int findNodeIndex(int row, int column){

	for (int i = 0; i < v.size(); ++i){
		if(v[i].column == column && v[i].row == row){
			return i;
		}
	}
	return -1;
}

int _getType(char c){

	switch(c){

		// tram floor
		case '.': return 2;
		// passenger
		case 'X': return 0;
		// ghe trong
		case 'L': return 1;
		default: return 0;
	}

}
char _getTypeName(int n){
	switch(n){

		// tram floor
		case 2: return '.';
		// passenger
		case 0: return 'X';
		// ghe trong
		case 1: return 'L';
		default:  return '.';
	}

}

void Debug(){

	Node n;
	for (int i = 0; i < v.size(); ++i){
		n = v[i];
		cout << _getTypeName(n.nodeType);
		cout << " rowIndex:" << n.row;
		cout << " columnIndex:" << n.column << endl;

	}
}

int getDirection(Point startP, Point targetP){

	int myDecided = LEFT; // gan mac dinh the da
	if(startP.row == targetP.row){
		// trai hoac phai
		if(startP.column < targetP.column){
			// di sang phai
			myDecided = RIGHT;
		}else{
			myDecided = LEFT;
		}
	}else if(startP.row < targetP.row){
		// di ve phia duoi
		myDecided = BOTTOM;
	}else{
		myDecided = TOP;
	}
	// moi chuyen se la the, tuy nhien o day co vat can nen ta phai xet tiep
	return myDecided;
}

Point getNextPoint(Point current, int direction){

	Point p;

	p.row = current.row;
	p.column = current.column;

	if(direction == LEFT){
			p.column -= 1;
	}else if(direction == RIGHT){
		p.column += 1;
	}
	else if(direction == TOP){
		p.row -= 1;
	}
	else{
		p.row += 1;
	}

	return p;
}

void debugPoint(Point p, int direction){
	if(direction == 1){
		cout << "LEFT:";
	}else if(direction == 2){
			cout << "RIGHT";
	}
	else if(direction == 3){
			cout << "BOTTOM";
	}else{
		cout << "TOP";
	}
	cout << "(" << p.row << "," << p.column<< ")"<< endl;
}


int findMinLen(Node x, Node l){

	vector<Point> pArr;
	vector<Point> checkInArr;
	// ta uu tien hang cot gan nhau
	/*
		X co the di: <-left, ->right , top , bottom
	*/	

	cout << "Tim duong di tu X " << x.row << ":" << x.column;
	cout << " den L " << l.row << ":"<< l.column;
	cout << endl;

	Point p;	
	Point nextPoint;
	Point targetPoint;
	p.row = x.row;
	p.column = x.column;

	targetPoint.row = l.row;
	targetPoint.column = l.column;

	int direction; // huong di
	Node nextNode;



	while(true){
		// tim huong di
		direction = getDirection(p, targetPoint);
		// tim vi tri cho buoc di tiep theo
		nextPoint = getNextPoint(p,direction);



		debugPoint(nextPoint, direction);
		// kiem tra neu vi tri tiep theo trung voi ghe ngoi thi dung lai
		if(nextPoint.row == l.row && nextPoint.column == l.column){
			break;
		}

		// neu gap vat can thi ta phai tinh toan lai duong di
		int nextNodeIndex = findNodeIndex(nextPoint.row, nextPoint.column);
		nextNode = v[nextNodeIndex];
		if(nextNode.nodeType != FLOOR){
			// cho nay khong on. ta phai tinh toan lai 
			if(direction == LEFT){
				// dang huong ve ben trai gap chuong ngai vat ta co the nghien cu re len hoac xuong
				// ta thu 
			}

		}else{
			// them vao danh sach cac diem da di qua hop le
			checkInArr.push_back(nextPoint);
		}

	}

	return 0;
}
// tim duong den cac ghe ngan nhat thi chon
void findL(Node n){
	int len = 0;
	int minLen = 0;

	for (int i = 0; i < v.size(); ++i){
			if(v[i].nodeType == SEAT){
				// neu la ghe thi ta tim duong di ngan nhat toi ghe
				len = findMinLen(n, v[i]);

				break;
			}
	}
}
// ta cho X di tim cac ghe
Line go(Node n){
	Line line;
	
	findL(n);

	return line;
}

int main(){
	
	int row, column;
	char c;

	cin >> row >> column;
	int nType = 0;

	for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				cin >> c;
				nType = _getType(c);
				addNode(i, j, nType);
			}
	}

	//Debug();

	for (int i = 0; i < v.size(); ++i){
			if(v[i].nodeType == PASSENGER){
				// di chuyen

				Line line = go(v[i]);
				break;// tam lay 1 cai da
			}
	}



	return 0;
}