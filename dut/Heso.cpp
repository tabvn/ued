#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Heso{
	vector<string> v;
};

vector<Heso*> arr;

string sum(string str1, string str2) 
{ 
    
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
   
    int carry = 0; 
  
    
    for (int i=n1-1; i>=0; i--) 
    { 
        
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
   
    if (carry) 
        str.push_back(carry+'0'); 
  
    
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

void findHeso(int k){

	Heso *h0 = new Heso();
	h0->v.push_back("1");
	arr.push_back(h0);

	Heso *h1 = new Heso();
	h1->v.push_back("1");
	h1->v.push_back("1");
	arr.push_back(h1);

	for (int i = 2; i <= k; ++i){
		Heso *hs = new Heso();
		for (int j = 0; j < i+1; ++j){
				if(j==0 || j == i){
					hs->v.push_back("1");
				}else{
					hs->v.push_back(sum(arr[i-1]->v[j], arr[i-1]->v[j-1]));
				}
		}

		arr.push_back(hs);

	}
	for (int i = 0; i < arr[k]->v.size(); ++i){
		cout << arr[k]->v[i] << endl;
	}
}

void clearMem(){
	for (int i = 0; i < arr.size(); ++i){
		delete arr[i];
	}
	arr.clear();
}
int main(){
	int k;
	cin >> k;

	findHeso(k);

	clearMem();

	return 0;
}