/*
Sample Tests:

4 4
.LX.
.X..
....
.L..

=> 1


4 4 
.XLX 
.X.. 
...L 
.X..

=>2

7 7 
...X.X. 
XL....L 
....... 
...L... 
.....XL 
....... 
...X...

 => 1

*/

#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

const int PASSENGER = 0;
const int SEAT = 1;
const int FLOOR = 2;

const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 3;
const int TOP = 4;

const int DEBUG = 0; // set 0 to turn off debug mode.

struct Node
{
	int nodeType;
	int row;
	int column;
	bool destroyed;
};


struct Point{
	int row;
	int column;
};

struct Line
{
	vector<Point> v;
	Node *node;
	Node *target;
	int len;
};

// array chua cac nodes

vector<Node> v;

void addNode(int row, int column, int nodeType){
	Node node;
	node.nodeType = nodeType;
	node.row = row;
	node.column = column;
	node.destroyed = false;

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

Point getNextPoint(Point p, int direction){


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
		cout << "Go left:";
	}else if(direction == 2){
			cout << "Go right";
	}
	else if(direction == 3){
			cout << "Go bottom";
	}else{
		cout << "Go top";
	}
	cout << "(" << p.row << "," << p.column<< ")"<< endl;
}


// X la passenger, L la ghe
Line findMinLen(Node *x, Node *l){


	Line line;
	line.len = 0;
	line.target = nullptr;
	line.node = x;
	line.v.clear();

	// ta uu tien hang cot gan nhau
	/*
		X co the di: <-left, ->right , top , bottom
	*/	

	if(DEBUG){
		cout << "Tim duong di tu X " << x->row << ":" << x->column;
		cout << " den L " << l->row << ":"<< l->column;
		cout << endl;
	}
	

	Point p;	
	Point nextPoint;
	Point targetPoint;
	p.row = x->row;
	p.column = x->column;

	targetPoint.row = l->row;
	targetPoint.column = l->column;

	int direction; // huong di
	Node nextNode;

	while(true){
		// tim huong di
		direction = getDirection(p, targetPoint);
		// tim vi tri cho buoc di tiep theo
		nextPoint = getNextPoint(p,direction);

		if(DEBUG ==1){
			debugPoint(nextPoint, direction);
		}
		
		// kiem tra neu vi tri tiep theo trung voi ghe ngoi thi dung lai
		if(nextPoint.row == l->row && nextPoint.column == l->column){
			line.target = l;
			break;
		}

		// them vao danh sach cac diem da di qua hop le
		p.row = nextPoint.row;
		p.column = nextPoint.column;
		line.v.push_back(p);
		// cong them do dai duong di
		line.len += 1;

		/*
		// neu gap vat can thi ta phai tinh toan lai duong di
		int nextNodeIndex = findNodeIndex(nextPoint.row, nextPoint.column);
		nextNode = v[nextNodeIndex];
		//  Neu de bai yeu cau ca vat can thi phai xet them cho nay
		if(nextNode.nodeType != FLOOR){
			// cho nay khong on. ta phai tinh toan lai 
			if(direction == LEFT){
				// dang huong ve ben trai gap chuong ngai vat ta co the nghien cu re len hoac xuong
				// ta thu 
			}

		}
		*/


	}

	return line;
}


// tim cac duong di
void go(Node *n, vector<Line> *arr){
	Line line;
	for (int i = 0; i < v.size(); ++i){
			
			if(v[i].nodeType == SEAT && v[i].destroyed == false){
				// neu la ghe thi ta tim duong di ngan nhat toi ghe
				line = findMinLen(n, &v[i]);
				if(line.target != nullptr){
					arr->push_back(line);
				}

			}
	}


}

bool ascSort(Line a, Line b){
	return a.len < b.len;
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


	int explosions = 0;

	vector<Line> lines; // mang chua tat cac cac duong di va muc tieu can den.
	for (int i = 0; i < v.size(); ++i){
			if(v[i].nodeType == PASSENGER){
				// di chuyen				
				go(&v[i], &lines);

			}
	}

	// sort tu thap len cao theo do dai duong di

	sort(lines.begin(), lines.end(), ascSort);

	// kiem tra xem co bao nhieu vu no xay ra
	for (int i = 0; i < lines.size(); ++i){

		if(lines[i].node->destroyed == true || lines[i].target->destroyed == true){
			
			continue;
		}

		bool hasExplosion = false;

		for (int j = 0; j < lines.size(); ++j){
			// ko so sanh voi chinh no

			if(lines[i].node->row == lines[j].node->row && lines[i].node->column == lines[j].node->column){
				// bo qua 
				continue;
			}

			if(lines[j].node->destroyed  || lines[j].node->destroyed || lines[j].target->destroyed){
				continue;
			}
			// kiem tra neu cung target va khoang cach bang nhau thi xay ra vu no

			if(lines[i].target->row == lines[j].target->row 
				&& lines[i].target->column == lines[j].target->column && lines[i].len == lines[j].len){
				hasExplosion = true;
				// boom
				lines[j].node->destroyed = true;
				
				if(DEBUG){
					cout << "Boom:" << endl;
					cout << lines[i].node->row << ":" << lines[i].node->column <<  " to " << lines[i].target->row << ":" << lines[i].target->column << " len:" << lines[i].len << endl;
					cout << lines[j].node->row << ":" << lines[j].node->column <<  " to " << lines[j].target->row << ":" << lines[j].target->column << " len:" << lines[j].len << endl;
					cout  << "---------"<< endl;

				}

			}

		}

		if(hasExplosion){
			// pha huy chinh no
			lines[i].node->destroyed = true;
			lines[i].target->destroyed = true;
			explosions++;
		}
	}

	cout << explosions;

	return 0;
}