#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Num {

private:
    int value;

public:

    Num(int value) {
        this->value = value;
    }

    vector<int> toBinary(int soBit) {
        vector<int> v;
        int num = value;
        while (num > 0) {
            v.push_back(num % 2);
            num /= 2;
        }

        if (v.size() < soBit) {
            for (int i = (int) v.size() - 1; i < soBit; ++i) {
                v.push_back(0);
            }
        }
        // đảo ngược mảng và lấy dưới lên
        reverse(v.begin(), v.end());

        return v;
    }


    /**
     * Đảo ngược mít :D
     * @param v
     */
    void bitReverse(vector<int> &v) {

        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == 0) {
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        }
    }

    /*
     * Cong them 1 vao day bit
     */
    void addOne(vector<int> &v) {

        int carry = 0;

        int startIndex = v.size() - 1;

        v[startIndex] += 1;
        if (v[startIndex] > 1) {
            v[startIndex] = 0;
            carry++;
        }


        startIndex--;

        while (carry > 0 && startIndex >= 0) {

            v[startIndex] += carry;
            carry--;
            if (v[startIndex] > 1) {
                v[startIndex] = 0;
                carry = 1;
            }
            startIndex--;
        }
    }

    vector<int> add(vector<int> v1, vector<int> v2) {

        vector<int> v;

        for (int i = 0; i < v1.size(); ++i) {
            v[i] = 0;
        }

        int carry = 0;
        int startIndex = (int) v1.size();
        while (startIndex >= 0) {
            v[startIndex] = v1[startIndex] + v2[startIndex];
            if (v[startIndex] > 1) {
                v[startIndex] = 0;
                v[startIndex] += carry;
                carry--;
                if (v[startIndex] > 0) {
                    v[startIndex] = 0;
                    carry++;
                }
            }
            startIndex--;
        }

        return v;
    }

    /**
     * Số bù 2
     * @param v
     */
    void twoComplement(vector<int> &v) {
        bitReverse(v);
        addOne(v);

    }

    bool isNegativeBinary(vector<int> &v) {
        return v[0] == 1;
    }

    void division(vector<int> q, vector<int> m) {

        cout << "hi" << q.size() << m.size();

        vector<int> lastA; // luu lai ket qua truoc do cua A
        vector<int> a;
        // khởi tạo A là mảng gồm các phần tử 0
        for (int i = 0; i < q.size(); ++i) {
            a[i] = 0;
            lastA[i] = 0;
        }

        twoComplement(m); // lấy phần bù của M, để công thay vì trừ

        int count = (int) q.size();
        int step = 1;

        int lastIndex = (int) q.size() - 1;
        while (count > 0) {

            // dich sang trai
            q[lastIndex] = a[0]; // phan tu cuoi cung cua Q se lay tu phan tu dau tien cua A
            a[lastIndex] = q[0]; // Phan tu cuoi cung cua A se lay thu phan tu dau tien cua Q

            for (int i = 0; i < lastIndex - 1; ++i) {
                a[i] = a[i + 1];
            }

            for (int j = 0; j < lastIndex - 1; ++j) {
                q[j] = q[j + 1];
            }

            // Ta cong A voi phan bu cua m
            vector<int> a1 = this->add(a, m);
            lastA = a;
            a = a1;

            //  kiem tra neu A < 0  hay > 0
            if (isNegativeBinary(a1)) {
                // A < 0;
                q[q.size() - 1] = 0;


            } else {
                a = a1;
                q[q.size() - 1] = 1;
            }


            count--;
        }


        cout << "Phan du:" << endl;

        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }

        cout << "Phan thuong:" << endl;

        for (int i = 0; i < q.size(); ++i) {
            cout << q[i] << " ";
        }


    }


    // phép chia
    void operator / (Num &anotherNum) {

        cout << "phep chia";

        vector<int> bin1;
        vector<int> bin2;

        if (this->value > anotherNum.value) {
            bin1 = this->toBinary(0);
            bin2 = anotherNum.toBinary((int) bin1.size());
            division(bin1, bin2);

        } else {
            bin2 = anotherNum.toBinary(0);
            bin1 = this->toBinary((int) bin2.size());
            division(bin2, bin1);
        }


    }


};

int main() {

    Num n1(7);
    Num n2(3);

    n1 / n2;
    return 0;
}