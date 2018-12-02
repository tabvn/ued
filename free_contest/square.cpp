#include<iostream> 
using namespace std; 


long long calculateSquare(long int hMin, long int hMax, long int wMin, long int wMax){

    long int h = hMax;
    long int w = wMax;
    long int a;

    while(true){

        if(h > w){
            a = w;
            if(h %w == 1 || h%w == 2){
                return a;

                break;
            }
        }else{

            a = h;

            if(w %h == 1 || w%h == 2){
                return a;
            }
        }

        if(h % a == 0 && w%a == 0){
            //cout << "h:" << h << " w:" << w << " a:" << a << endl;
            break;
        }
        a--;
        h--;
        w--;
    }

    return a;
}
int main() 
{   


    int n;
    long int hMin, hMax, wMin, wMax;

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> hMin >> hMax >> wMin >> wMax;
        cout << calculateSquare(hMin, hMax, wMin, wMax) << endl;
    }
    return 0; 
} 