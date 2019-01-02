#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("input.txt");  // dau vao
ofstream fo("output.txt");  // dau ra

int main(int argc, char const *argv[]){
	
	// lay gia tri tu file input.txt

	int n;

	fi >> n;

	// xuat gia tri n +1  ra file output.txt

	fo << (n +1); 

	// dong file
	fo.close();
	fi.close();
	return 0;
}