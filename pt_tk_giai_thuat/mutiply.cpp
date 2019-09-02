#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Multiply {

    struct Row {
        vector<int> v;
    };

    vector<Row> rows;
    vector<int> v1, v2;

    Multiply(string s1, string s2) {

        for (int i = 0; i < s1.size(); ++i) {
            Multiply::v1.push_back(s1[i] - '0');
        }
        for (int i = 0; i < s2.size(); ++i) {
            Multiply::v2.push_back(s2[i] - '0');
        }

    }

    Multiply *calculate() {

        if (v1.empty() || v2.empty()) {
            return this;
        }


        int level = 0;

        for (int i = v2.size() - 1; i >= 0; --i) {
            int carry = 0;
            Row row;
            for (int k = 0; k < level; ++k) {
                row.v.push_back(0);
            }
            for (int j = v1.size() - 1; j >= 0; --j) {
                int value = v1[j] * v2[i] + carry;
                row.v.push_back(value % 10);
                carry = value / 10;
            }
            if (carry > 0) {
                row.v.push_back(carry);
            }
            rows.push_back(row);
            level++;


        }

        // cong cac hang lai voi nhau
        int maxSize = rows[0].v.size();
        for (int i = 0; i < rows.size(); ++i) {
            if (rows[i].v.size() > maxSize) {
                maxSize = rows[i].v.size();
            }
        }

        // tao matran dong cot maxSize
        int arr[maxSize][maxSize];

        // set all members of array = 0
        for (int i = 0; i < maxSize; ++i) {
            for (int j = 0; j < maxSize; ++j) {
                arr[i][j] = 0;
            }
        }

        for (int i = 0; i < rows.size(); ++i) {
            Row row = rows[i];
            for (int j = 0; j < row.v.size(); ++j) {
                arr[i][j] = row.v[j];
            }
        }


        vector<int> result;
        int carry = 0;

        for (int column = 0; column < maxSize; ++column) {
            int value = 0;
            for (int row = 0; row < maxSize; ++row) {
                 value += arr[row][column];
            }
            value += carry;
            result.push_back(value %10);
            carry = value /10;

        }
        if(carry > 0){
            result.push_back(carry);
        }


        // output
        for (int i = 0; i < result.size() - v1.size(); ++i) {
            cout << "  ";
        }

        for (int i = 0; i < v1.size(); ++i) {
            cout << v1[i] << " ";
        }

        cout << endl;
        for (int i = 0; i < result.size(); ++i) {
            if(i == 0){
                cout << "* ";
            }else{
                cout << " ";
            }
        }

        cout << endl;

        for (int i = 0; i < result.size() - v2.size(); ++i) {
            cout << "  ";
        }

        for (int i = 0; i < v2.size(); ++i) {
            cout << v2[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < maxSize; ++i) {
            cout << "--" ;
        }
        cout << endl;
        for (int i = result.size() -1; i >= 0; --i) {
            cout << result[i] <<" ";
        }

        return this;


    }

};

int main() {

    Multiply *multiply = new Multiply("567", "1234");
    multiply->calculate();

    return 0;
}
