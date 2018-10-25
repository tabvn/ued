#include <iostream>
#include <fstream>
#include <vector>
#import <cstdlib> // khai báo để tí nữa dùng hàm abs


using namespace std;

ifstream fi ("/Users/toan/ued/18-10-2018/GOMIN.INP");
ofstream fo ("/Users/toan/ued/18-10-2018/GOMIN.OUT");

int n,t;
int x; // toa do cac n qua min
int k; // toa do qua min hen gio


struct Node
{
	vector<int> v; // mảng gồm các index toạ độ đường 
	long long length;
};

Node node;

vector<int> v; // mảng gồm các toạ độ của các quả mìn.
vector<int> startPointArr; // mảng gồm các điểm đầu
vector<Node> nodes;



/**
Tinh toan do dai 2 diem x1 -> x2
*/
int calculatePointLength(int x1, int x2){

	x1 = abs(x1);
	x2 = abs(x2);

	if(x1 > x2){
		return x1 - x2;
	}

	return x2 - x1;

}


void display(){
	for (int i = 0; i < nodes.size(); ++i){
			
			for (int j = 0; j < nodes[i].v.size(); ++j){
				cout << v[nodes[i].v[j]] << " ";
			}
			cout << " length:" << nodes[i].length;
			cout << endl;
	}
}

/*
*Kiem tra xem cong viec da xong chua
*/
bool isDone(vector<int> vArr){
	for (int i = 0; i < vArr.size(); ++i){
		if(vArr[i] != -1){
			return false;
		}
	}
	return true;
}

/*
* Liệt kê các đường đi
*/

void list(){

	

	int totalTime = 0;
	int timerBoomIndex = k -1;
	vector<int> pointArr; // ta chỉ lưu gia trị index

	// copy vector
	for (int i = 0; i < v.size(); ++i){
		pointArr.push_back(i);
	}


	bool resolveTimerBoom = false;
	int lastPointIndex = -1;
	bool isGoingleft = true;

	for (int i = 0; i < startPointArr.size(); ++i){
		node.v.clear();
		node.length = 0;
		node.v.push_back(startPointArr[i]);

		//neu điểm đầu mà trùng với vị trí bom hẹn giờ thì ta đánh dấu là đã gỡ xong quả hẹn giờ, và chỉ việc gỡ quả khác
		if(timerBoomIndex == startPointArr[i]){
			pointArr[timerBoomIndex] = -1;
			resolveTimerBoom = true;
		}

		// ta đi về bên trái trước
		lastPointIndex = startPointArr[i];
		for (int j = startPointArr[i]; j >= 0; --j){

			/**
			vừa đi lại vừa kiểm tra nếu thời gian quay lại mà lơn hơn t thì bỏ điểm vừa đến
			*/

			int pointLength = calculatePointLength(v[lastPointIndex], v[pointArr[j]]);

			if((calculatePointLength(v[j], v[timerBoomIndex])+ pointLength) * 2  >= t && !resolveTimerBoom){
				// không ổn, vì khi quay lại sẽ ko còn thời gian nữa, tèo rồi :D
				// tot nhat la nen quay lai
				// ta lại đổi hướng sang phải, và phải quay lại gở quả mìn hẹn giờ đã

				node.length += calculatePointLength(v[j], timerBoomIndex);
				pointArr[timerBoomIndex] = -1;
				lastPointIndex = timerBoomIndex;

				/* nhu vay ta quay lại gỡ quả mìn hẹn giờ, 
					ở đây phân vân là sau khi gỡ xong quả mìn hẹn giờ thi nên đi về trái hay phải ?
				*/

				/* ta thử đi về phia bên phải rồi tính đây là 1 đường  , hoặc có thể kiểm tra độ dài từ 
					điểm hiện tại đến vị trí phải bao xa, từ vị trí hiẹn tại về trái bao xa 
					nếu left > right => đi về phia phải
					hoặc là bên trái đã xong hêt rồi thì ta đương nhiên là phải đi về bên phải
				*/

				int rightLength = 0;
				int leftLength = 0;
				int lastRightPoint = -1;
				int lastLeftPoint = -1;

				for (int ii = lastPointIndex; ii < pointArr.size(); ++ii){
					if(pointArr[ii] != -1){
						rightLength += calculatePointLength(v[pointArr[ii]], lastPointIndex);
						lastRightPoint = pointArr[ii];
					}
				}

				for (int ii = lastPointIndex; ii >= 0; --ii){
					if(pointArr[ii] != -1){
						rightLength += calculatePointLength(v[pointArr[ii]], lastPointIndex);
						lastLeftPoint = ii;
					}
				}

				if(leftLength > rightLength){
					// go right
					node.length += calculatePointLength(lastPointIndex, v[lastRightPoint]);
					for (int ii = pointArr.size() -1; ii >= 0; ++ii){
						if(pointArr[ii] != -1){
							node.length += calculatePointLength(lastPointIndex, ii);
							node.v.push_back(ii);
							pointArr[ii] = -1;// đánh dấu gỡ xong
							lastPointIndex = pointArr[ii];
						}
						
					}

				}else{
					// go left;
					


				}

				


				isGoingleft = false;

				break;
			}

			// them vi trí điểm vào mảng 
			if(pointLength > 0){
				// đồng thời tính luôn độ dài
				node.v.push_back(j);
				node.length += pointLength;

				// danh dấu là đã gỡ
				pointArr[j] = -1;

			}

			lastPointIndex = j;
		}

		// ta kiem tra neu 

		/*
		sau khi đi về phía bên trái , ta tiếp tuc đi về phía bên phai
		giờ ta tính độ dài đến điểm phia bên phải của vị trí bắt đầu , 
		đồng thời kiểm tra xem nếu quả mìn hẹn giờ vẫn chưa gỡ thì ta phải tính xem thơi gian đến nó có đủ ko

		**/

		if(isDone(pointArr)){
			cout << "Done";
			break;
		}

		//node.length += calculatePointLength(lastPointIndex, startPointArr[i]);

		// ta di ve phia ben phai
		for (int j = pointArr[lastPointIndex]; j < pointArr.size(); ++j){
			if(pointArr[j] != -1){
				int l = calculatePointLength(lastPointIndex, v[pointArr[j]]);
				if(l > 0){
					node.length += l;
					node.v.push_back(v[pointArr[j]]);
				}
				
			}
		}

		// them vao nodes
		nodes.push_back(node);

		node.v.clear();
		node.length = 0;

	}


	display();
}

int main(){

	fi >> n >> t;

	for (int i = 0; i < n; ++i){
		fi >> x;
		v.push_back(x);
	}

	fi >> k;

	// ta tim cac duong di , sao cho chon vi tri bat dau den vi tri hen gio thoa man
	// roi sau do tinh tong do dai, chon cai nao co do dai be nhat thi lay

	for (int i = 0; i < v.size(); ++i){
		/* ta liet ke tat ca cac diem bat dau thoa man yeu cau, 
		sao cho khi cham vao qua min dau tien
		thi doan noi diem bat dau toi qua min hen gio toa do k, 
		se co độ dài < t(thơi gian quả mình hẹn giờ sẽ nổ);
		*/

		// k là vị trí đếm của của mìn hẹn giờ, tuy nhiên thứ tự trong mảng sẽ là k-1
		if(calculatePointLength(v[i], v[k-1]) < t){
			/* nếu độ dài 2 điểm < thời gian quả bom hẹn giờ nổ thì thoả mãn. 
			(vì thời gian hẹn giờ bằng khoảng cách di chuyển)
			*/

			startPointArr.push_back(i);
		}
	}
	// vậy ta đã có được các điểm bắt đầu cho đường đi gỡ mìn.

	/*
	Ta đi liệt kê các đường đi tới quả mìn hẹn giờ, có thể đi sang trái hoặc phải:
	+ nếu start point index < (k -1 ) điểm đầu < điểm cần đến, nên ta đi về phía phải
	+ nếu bằng thì điểm bắt đầu trùng với toạ độ quả mìn hẹn giờ 
	+ còn lại index > (k - 1) : ta đi về phia bên trái
	*/

	list();


	return 0;
}