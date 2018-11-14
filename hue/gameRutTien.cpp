#include <iostream>
#include <vector>
using namespace std;

const int KEO = 0; // KEO la nguoi di duoc

struct Money
{
    int value;
    bool isTaken;
    int index;
    Money(int value, int index){
        this->index = index;
        this->isTaken = false;
        this->value = value;
        
    }
};

struct Taken{
    long long value;
    int length;
    int player;
    
};
vector<Money*> v;
vector<Taken> takens;

void addMoney(int value, int index){
    Money *m = new Money(value, index);
    v.push_back(m);
}


long long calculateTotal(int fromIndex, int numOfMoneyCanTake){
    
    long long total = 0;
    
    int maxIndexCanTake = fromIndex+numOfMoneyCanTake;
    if(maxIndexCanTake > v.size()){
        maxIndexCanTake = v.size();
    }
    
    for (int i = fromIndex; i < maxIndexCanTake; ++i){
        total += v[i]->value;
    }
    
    return total;
}


int currentIndex = -1;

void play(int player){
    
   // cout << "Hien tai:" << currentIndex << endl;
    
    
    
    int maxTakenNumber = 2;
    int lastTakenIndex = (int) (takens.size() -1);
    long long sum = 0;
    
    
    int nexIndex;
    long long moneyValue = 0;
    long long maxMoneyValue = 0;
    
    long long nextMoneyValue = 0;
    long long maxNextMoneyValue = 0;
    int preferTakenNumber = 2;
    int minNextValue;
    
    
    // toi uu luot lay cho moi nguoi sao cho moi lan nay dc nhieu nhat va lan sau phai co tong nho hon lan truoc
    
    if(player == 0){
        // keo thi chi lay dc toi da 2 dong
        
        sum = 0;
        maxTakenNumber = 2;
        // if maX
        if(maxTakenNumber > 1){
            // ta xet gia su keo lay 2
            nexIndex = currentIndex +1;
            moneyValue = 0;
            maxMoneyValue = 0;
            maxMoneyValue = 0;
            
            nextMoneyValue = 0;
            maxNextMoneyValue = 0;
            preferTakenNumber = 1;

            int rate = 1000000;
           
            
            for (int i = 1; i <= maxTakenNumber; ++i){
                moneyValue = calculateTotal(nexIndex, i);
                //cout << "Neu lay:" << moneyValue << endl;
                maxNextMoneyValue = 0;
                for (int j = 1; j <= i*2; ++j){
                    nextMoneyValue = calculateTotal(nexIndex+i, j);
                    if(nextMoneyValue > maxNextMoneyValue){
                    	maxNextMoneyValue = nextMoneyValue;
                    }
                }

                if(nextMoneyValue - moneyValue < rate){
                			//cout << "Luot toi rate:" << (nextMoneyValue - moneyValue) << endl;
                    	rate = nextMoneyValue - moneyValue;
                    	preferTakenNumber = i;
                 }
                    
                
              
                
            }
            
            maxTakenNumber = preferTakenNumber;
        }
        
    }else{
        // thi co the lay dc toi da la 2x // phu thuoc vao so lan lay truoc do
        maxTakenNumber = takens[lastTakenIndex].length *2;
         
        if(maxTakenNumber > 1){
            nexIndex = currentIndex +1;
            moneyValue = 0;
            maxMoneyValue = 0;
            
            nextMoneyValue = 0;
            maxNextMoneyValue = 0;
            preferTakenNumber = 1;
            
             int rate = 1000000;
           
            
            for (int i = 1; i <= maxTakenNumber; ++i){
                moneyValue = calculateTotal(nexIndex, i);
                //cout << "Neu lay:" << moneyValue << endl;
                maxNextMoneyValue = 0;
                for (int j = 1; j <= 2; ++j){
                    nextMoneyValue = calculateTotal(nexIndex+i, j);
                    if(nextMoneyValue > maxNextMoneyValue){
                    	maxNextMoneyValue = nextMoneyValue;
                    }
                }

                if(nextMoneyValue - moneyValue < rate){
                			//cout << "Luot toi rate:" << (nextMoneyValue - moneyValue) << endl;
                    	rate = nextMoneyValue - moneyValue;
                    	preferTakenNumber = i;
                 }
                    
                
              
                
            }
            
            
            maxTakenNumber = preferTakenNumber;
            
            
        }
        
    }
    
    
    
    
    int theNextIndex = currentIndex +1;
    
    Taken taken;
    
    taken.value = 0;
    taken.player = player;
    taken.length = maxTakenNumber;
    long long totalValue = 0;
    
    
    int maxIndex = theNextIndex + maxTakenNumber;
    if(maxIndex > v.size()){
        maxIndex = v.size();
    }
    for (int i = theNextIndex; i < maxIndex; ++i){
        totalValue += v[i]->value;
        currentIndex = i;
        v[i]->isTaken = true;
    }
    

    //cout << "Luot choi:" << player << " take:" << maxTakenNumber << " value:" << totalValue << endl;
    taken.value = totalValue;
   
    takens.push_back(taken);
    
    
    
}


void finish(){
    
    long long keoValue = 0;
    long long banhValue = 0;
    
    for (int i = 0; i < takens.size(); ++i){
        if(takens[i].player == KEO){
            keoValue += takens[i].value;
        }else{
            banhValue += takens[i].value;
        }
    }
    
    
    cout << keoValue;
}

int main(){
    int n,ci;
    
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> ci;
        addMoney(ci, i);
    }
    
   if(n == 1){
   	cout << v[0]->value;
   } else if(n == 2 || n==3){
  		cout << (v[0]->value + v[1]->value);
   }else{
   	 int p = 0;
	   for (int i = 0; i < v.size(); ++i){
		   	play(p);
		   	p = !p;
		   	if(currentIndex == v.size() - 1){
		   		break;
		   	}
	   }

	  finish();
	  
   }
   
    
    return 0;
}
