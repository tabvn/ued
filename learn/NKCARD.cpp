#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int firstIndex = 0;
int secondIndex = 1;

void AddNum(int n){
    v.push_back(n);
}


int findFirstIndex(int min){
    int d = -1;
    
    int increase = 0;
    
    for (int i = firstIndex; i < v.size(); i++) {
        
        if(v[i] != -1 && increase >= min){
            d = i;
            
            break;
        }
        if(v[i] != -1){
            increase ++;
        }
        
        
    }
    
    return d;
    
}

int main(){
    
    
    
    int m,k;
    string s;
    
     cin >> m >> k;
     getline(cin, s, '.');
    
    /* s = "ABBABA";
     m = 6;
     k = 3;
     */
    
    
    
    
    for (int i = 0; i < m; i ++) {
        AddNum(i);
    }
    
    
    
    
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == 65){
        
            AddNum(v[firstIndex]);
            v[firstIndex] = -1;
            
            
            if( (firstIndex+1 < s.size()) && v[firstIndex+1] == -1){
                firstIndex = secondIndex;
                secondIndex++;
            }else{
                
                 firstIndex ++;
                 secondIndex++;
            }
            
            
        }
        if(s[i] == 66){
          
            AddNum(v[secondIndex]);
            
            v[secondIndex] = -1;

            secondIndex++;
        }
    }
    

    
    // tim K
    
    int vitri = 0;
    
    for (int i = k-1; i <= k+1; i++){
        vitri = findFirstIndex(i);
        if(i != k -1){
            cout << " ";
        }
        cout << v[vitri];
        
    }
    
    
    
    return 0;
}
