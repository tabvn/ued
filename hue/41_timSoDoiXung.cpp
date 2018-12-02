#include <iostream>
#include <vector>

using namespace std;


vector<string> v;

int paseInt(char c) {
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}

char paseChar(int i) {
    switch (i) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '0';
    }
}

void clean(string &s) {

    for (int i = 0; i < int(s.size() - 1); ++i) {
        if (s[i] == '0') {
            s.erase(i, 1);
        } else {
            break;
        }

    }
    if (s[0] == '0' && s.size() > 1) {
        s.erase(0, 1);
    }


}

bool isAll9Degits(string s) {

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '9') {
            return false;
        }
    }
    return true;
}

void findSmallestPalin(string s) {

    int len = (int) s.size();
    int remember = 0;
    bool hasIncrease = false;

    if (s.size() == 1) {
        int sumNumber = paseInt(s[0]) + 1;
        if (sumNumber > 9) {
            cout << 11;
        } else {
            cout << sumNumber;
        }

    } else if (isAll9Degits(s)) {
        cout << 1;
        for (int i = 0; i < len - 1; ++i) {
            cout << 0;
        }
        cout << 1;
    } else {


        bool isIncreased = false;

        for (int i = len - 1; i >= 0; --i) {
            if (i <= len - i - 1) {
                break;
            }
            if (paseInt(s[i]) > paseInt(s[len - i - 1])) {

                //cout << "should remember:";
                remember = -1; // muon 1
            }

            if (paseInt(s[i]) < paseInt(s[len - i - 1])) {

                //cout << "not remember" << s[i] << " :" << paseInt(s[len-i-1]) << endl;
                remember = 0;
                hasIncrease = true;
            }

            s[i] = paseChar(paseInt(s[len - i - 1]));
        }

        //cout << "rememer:" << remember<<endl;
        if (!hasIncrease || remember == -1) {
            for (int i = len / 2; i >= 0; --i) {
                // tang vi tri 2 len 1 don vi
                //cout << "tang:" << s[i] << " index:" << i<< endl;
                int num = paseInt(s[i]) + 1;
                remember = 0;
                if (num > 9) {
                    num = 0;
                    remember = -1;
                }

                s[i] = paseChar(num);
                
                if(paseInt(s[len-i-1]) < 9 || i < (len -i -1)){
                    s[len - i - 1] = paseChar(num);
                }
                
                

                if (remember == 0) {
                    break;
                }

            }
        }


        if (remember == -1) {
            // them so 1 phia truoc
            cout << 1;
            for (int i = 0; i < len - 1; ++i) {
                cout << 0;
            }
            cout << 1;

        } else {
            cout << s;
        }


    }


}

int main() {
    long long t;
    string s;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); ++i) {
        s = v[i];
        clean(s);
        findSmallestPalin(s);
        cout << endl;
       

    }

    return 0;
}