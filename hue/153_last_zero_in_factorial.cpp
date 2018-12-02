#include<iostream>
#include<math.h>
using namespace std;
 
int findTrailingZeros(int n) 
{ 
    int count = 0; 
    // Keep dividing n by powers of  
    // 5 and update count 
    for (int i = 5; n / i >= 1; i *= 5) 
        count += n / i;
    return count; 
} 

int main()
{
	int n,b;
	int numOfZero,p,k,c;
	cin >> b >> n;

	numOfZero = n;
  int j=b;
  for (int i=2; i <= b; i++)
  {
    if (j%i==0)
    {   
       p=0;
       while (j%i==0)
       {
             p++;
             j/=i;
       }
       c=0;
       k=n;
       while (k/i>0)
       {
             c+=k/i;
             k/=i;
       }
       numOfZero=min(numOfZero,c/p);
    }
  }
   cout << numOfZero;
   return 0;

}