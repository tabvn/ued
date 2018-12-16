#include <iostream> 
using namespace std;

const int isDebugMode = 0;

struct Pos
{
	int row,column;
};

Pos p;

int jump = 0;

void logMessage(string message){

	if(isDebugMode){
		cout << message << endl;
	}
}


void solve(){

	const int center = 2;
	while(true){

		if(p.row == center && p.column == center){
			break;
		}
		if(p.row > center){
			// go left
			p.row -= 1;
			jump++;

			logMessage("Go left");

		}else if(p.row < center){
			// go right
			p.row += 1;
			jump++;

			
			logMessage("Go right");

		}else {

				if(p.column > center){
					p.column -=1;
					jump++;
					
					logMessage("Go top");

				}else if(p.column < center){
					p.column += 1;
					jump++;
					logMessage("Go bottom");

				}else{

					break;
				}
		}
	}

	cout << jump;
}

int main(int argc, char const *argv[]){
	
	const int N = 5;

	int a[N][N];

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cin >> a[i][j];
			if(a[i][j] == 1){
				p.row = i;
				p.column = j;
			}
		}
	}

	


	solve();

	return 0;
}