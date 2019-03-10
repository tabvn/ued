
#include <iostream>
#include <math.h>

#ifdef _WIN32
#include "windows.h"
#include <conio.h>
#endif

using namespace std;

#ifdef _WIN32
void gotoxy(int x, int y)
{
  COORD cur = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}
#else

char getch() {

}

void gotoxy(int x, int y) {
    printf("\033[%dG\033[%dd", x + 1, y + 1);
}

#endif

int textcolor(int Color) {

#ifdef _WIN32
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    return SetConsoleTextAttribute(h, Color);
#endif

}

#define CYAN 10
#define YELLOW 14

int n = 0, m = 0, A[50], B[50];

int KTra(int x, int n, int A[]) {
    for (int i = 0; i < n; i++)
        if (x == A[i]) return 1;
    return 0;
}

void Insert(int x, int &n, int A[]) {
    if (KTra(x, n, A) == 0) {
        A[n] = x;
        n++;
    }
}

void View(int n, int A[]) {
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << "  ";
}

void Bosung(int &n, int A[]) {
    char ch;
    int x;
    do {
        cout << "\nNhap x= ";
        cin >> x;
        Insert(x, n, A);
        cout << "\nNhan <ESC> de ket thuc nhap!";
#ifdef _WIN_32
        ch = getch();
#endif
    } while (ch != 27);
}

int Tong(int n, int a[]) {
    if (n == 0) return 0;
    else return a[n] + Tong(n - 1, a);
}

void Nhap(int &n, int a[]) {
    cout << endl << "Nhap n = ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << endl << "A[" << i << "]=";
        cin >> a[i];
    }
}

void Baitap7() {
    system("cls");
    cout << endl << "Tinh tong mang";
    int n, a[100];
    Nhap(n, a);
    cout << endl << "Tong mang = " << Tong(n, a);
    getch();
}

//Viet xau s ra man hinh tai toa do (x,y) voi mau la color
void Write(char *s, int x, int y, int color) {
    textcolor(color);
    gotoxy(x, y);
    cout << s;
    textcolor(15);
}

void Khung(int x1, int y1, int x2, int y2) {
    int x, y;
    gotoxy(x1, y1);
    cout << "É";
    gotoxy(x2, y1);
    cout << "»";
    gotoxy(x1, y2);
    cout << "È";
    gotoxy(x2, y2);
    cout << "¼";
    for (x = x1 + 1; x < x2; x++) {
        gotoxy(x, y1);
        cout << "Í";
        gotoxy(x, y2);
        cout << "Í";
    }
    for (y = y1 + 1; y < y2; y++) {
        gotoxy(x1, y);
        cout << "º";
        gotoxy(x2, y);
        cout << "º";
    }
}

/*Tao ra menu tai toa do (x0,y0) voi n dong luu trong bien s
chon: dong menu hien thoi (khac mau voi cac dong khac) */
void Ve_menu(int x0, int y0, int chon, int n, char *s[]) {
    system("cls");
    Khung(x0 - 2, y0 - 1, x0 + 30, y0 + n);
    for (int i = 0; i < n; i++)
        if (i == chon) Write(s[i], x0, y0 + i, CYAN);
        else Write(s[i], x0, y0 + i, YELLOW);
    Write("Copyright (c) 2016 by Pham Anh Phuong.", x0 - 4, y0 + n + 5, 10);
}




// Bai Tap

int ucln(int a, int b) {

    if (a == b) {
        return a;
    }

    if (a > b) {
        return ucln(a - b, b);
    }

    return ucln(a, b - a);

}

void baitap1() {

    int a, b;

    cout << "Nhap A: ";
    cin >> a;

    cout << "Nhap B: ";

    cin >> b;

    cout << ucln(a, b);


}

int count(int n) {
    int total = 0;
    while (n > 0) {
        n /= 10;

        total++;
    }

    return total;
}

int recusiveCount(int n, int total) {

    if (n == 0) {
        return total;
    }
    return recusiveCount(n / 10, total + 1);
}


void baitap2() {

    int n;

    cout << "Nhap so nguyen duong N: ";

    cin >> n;

    cout << "Dem theo cach khong de quy:" << count(n) << endl;

    cout << "Dem theo cach dung de quy: " << recusiveCount(n, 0);

}

long long fib(int n) {
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);

}


void baitap3() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Ket qua Fib(" << n << ") = " << fib(n);

}


long long ackermann(int m, int n) {

    if (m == 0) {
        return n + 1;
    }

    if (n == 0) {
        return ackermann(m - 1, 1);
    }

    return ackermann(m - 1, ackermann(m, n - 1));
}

void baitap4() {


    int m, n;

    cout << "Nhap m: ";

    cin >> m;

    cout << "Nhap n: ";
    cin >> n;

    cout << "A(" << m << "," << n << ") = " << ackermann(m, n);
}

bool isP(string s, int left, int right){
    if(s.size() ==1 || left >= right){
        return true;
    }

    if(s[left] != s[right]){
        return false;
    }

    return isP(s, left+1, right-1);
}

void baitap5(){

    string s;

    cout << "Nhap chuoi can kiem tra: ";

    cin >> s;

    if(isP(s, 0 , s.size() -1)){
        cout << "Chuoi doi xung";
    }else{
        cout << "Chuoi khong doi xung";
    }


}

long long sum(int n){

    long long s = 0;

    for (int i = 1; i <= n; ++i){
        s+= i;
    }

    return s;
}

long long recursiveSum(int n){

    if(n == 1){
        return 1;
    }

    return n + recursiveSum(n-1);

}

void  baitap6a(){

    int n;

    cout << "Nhap N: ";

    cin >> n;

    cout << "ket qua khong dung de quy: " << sum(n) << endl;
    cout << "ket qua dung de quy: " << recursiveSum(n);

}


/*
Tổng nghịch đảo dạng phân số
*/
struct PhanSo
{
    long long tu,mau;

    PhanSo(long long tu, long long mau){
        this->tu = tu;
        this->mau = mau;
    }

    long long gcd(long long a, long long b){
        if(a %b == 0){
            return b;
        }
        if(b%a == 0){
            return a;
        }
        while(a != b){
            if(a > b){
                a = a-b;
            }else{
                b = b -a;
            }
        }

        return a;
    }
    PhanSo operator + (const PhanSo &b){


        // 1/2 + 1/3
        long long tuSo, mauSo;


        tuSo = (this->tu * b.mau) + b.tu * this->mau;
        mauSo = this->mau * b.mau;
        long long uc = this->gcd(tuSo, mauSo);
        return PhanSo(tuSo/uc, mauSo/uc);
    }

    void print(){
        cout << this->tu << "/" << this->mau;
    }

};


void sum_b(int n){

    PhanSo p(1,1);


    for (int i = 2; i <= n; ++i){
        p = p + PhanSo(1, i);
    }

    p.print();
}

PhanSo recurseSum(int n){
    if(n == 1){
        return PhanSo(1, 1);
    }
    return PhanSo(1, n) + recurseSum(n-1);
}

void baitap6b(){

    int n;

    cout << "Nhap N: ";
    cin >> n;

    cout << "Tinh tong phan so khong dung de quy: ";
    sum_b(n);
    cout << endl;

    cout << "Tinh tong phan so dung de quy: ";

    PhanSo kq = recurseSum(n);
    kq.print();



}



void sub(int n){

    PhanSo p(1,1);


    for (int i = 2; i <= n; ++i){
        p = p + PhanSo(1 * pow(-1, i+1), i);


    }

    p.print();
}

PhanSo recurseSub(int n){
    if(n == 1){
        return PhanSo(1, 1);
    }
    return PhanSo(1 * pow(-1, n+1) , n)  + recurseSub(n-1);

}

void baitap6c(){

    int n;

    cout << "Nhap N: ";
    cin >> n;

    cout << "Ket qua khong dung de quy: ";
    sub(n);
    cout << endl;

    cout << "ket qua dung de quy: ";

    PhanSo kq = recurseSub(n);
    kq.print();


}


long double *a;

double toRadial(int x){
    return x*3.14159265359/180;
}

long double p(double sinx, int n){

    long double v = a[n];

    if(v != -1){
        return v;
    }

    v = 1;
    for (int i = 1; i <= n; ++i){
        v*= sinx;
        a[i] = v;
    }


    return v;
}

long double tongSin(int n, double x){

    long double s = 0;
    long double sinX = sin(x);
    for (int i = n; i >=0; --i){
        long double v = a[i];
        s+= p(sinX, i);

    }

    return s;

}

long double tongSinDequy(int n, double x){

    if(n== 0){
        return 1;
    }

    long double sinX = sin(x);

    return p(sinX, n) + tongSinDequy(n-1, x);
}

void baitap6d(){


    int n;
    int x;
    cout << "Nhap N: ";
    cin >> n;
    // khoi tao mang cached
    a = new long double[n+1];
    for (int i = 0; i <= n; ++i){
        a[i] = -1;
    }

    cout << "Nhap X (degree): ";

    cin >> x;

    cout << "Ket qua khong dung de quy: " << tongSin(n,toRadial(x)) << endl;

    cout << "Ket qua dung de quy: " << tongSinDequy(n,toRadial(x));

}

long long cn(int n, int k){

    if(k==0 || n == k){
        return 1;
    }

    return cn(n-1, k-1) + cn(n-1, k);
}
void baitap7(){
    int n,k;

    cout << "Nhap N: ";
    cin >> n;
    cout << "Nhap K: ";
    cin >> k;

    cout << "Ket qua to hop chap k cua N la: " << cn(n, k);

}


int daoSo(int n){

    int ds = 0;
    int tmp;
    while(n > 0){
        tmp = n%10;
        ds = ds * 10 + tmp;
        n/= 10;
    }

    return ds;
}

int daoSoDequy(int n, int kq){

    if(n == 0){
        return kq;
    }

    return daoSoDequy(n/10, kq*10+n%10);
}

void baitap8(){
    int n;

    cout << "Nhap vao N: ";
    cin >> n;
    cout << "So dao nguoc cua N: " << daoSo(n) << endl;
    cout << "So dao nguoc cua N dung de quy: " << daoSoDequy(n, 0);

}

int aa[8];
const int nn = 8;

bool isOK(int x, int y){

    for(int i = 1; i< x; i++ ){

        if(aa[i] == y){
            // chung cột
            return false;
        }

        if(abs(aa[i] - y) == abs(i-x)){
            // duong cheo // cong thuc copy
            return false;
        }

    }

    return true;
}

void print(){
    for (int i = 1; i <= nn; ++i){
        cout << aa[i] << " ";
    }
    cout << endl;
}

void Try(int i){

    for (int j = 1; j <= nn; ++j){
        if(isOK(i, j)){
            // dat tai hang i cot j
            aa[i] = j;
            if(i == nn){
                print(); // in ra phuong an
            }
            Try(i+1); // tang hang len 1
        }
    }
}
void baitap9(){

    Try(1);
}

// Ket thuc bai tap

int main() {
    char ch, *st[20];
    system("cls");

    st[0] = "B1: UCLN";
    st[1] = "B2: Dem chu so";
    st[2] = "B3: Fibonacci";
    st[3] = "B4: Ackermann";
    st[4] = "B5: So doi xung";
    st[5] = "B6a: 1+2 +3+......+n";
    st[6] = "B6b: 1+1/2 + .....+ 1/n ";
    st[7] = "B6c: 1-1/2+......";
    st[8] = "B6d: 1 + sin(x)+...";
    st[9] = "B7: To hop chap k cua N";
    st[10] = "B8: Dao so";
    st[11] = "B9: 8 quan hau";

    const int end_index = 12;
    st[end_index] = "<ESC> Ket thuc chuong trinh!";
    int x0 = 25, y0 = 10, chon = 0, luuchon, sodong = end_index + 1, ok = false;
    Ve_menu(x0, y0, chon, sodong, st);
    do {
        ch = getch(); //Nhan mot phim
        switch (ch) {
            case 72: //phim len
                luuchon = chon;
                chon--;
                if (chon < 0) chon = sodong - 1;
                Write(st[luuchon], x0, y0 + luuchon, YELLOW);
                Write(st[chon], x0, y0 + chon, CYAN);
                break;
            case 80://phim xuong
                luuchon = chon;
                chon++;
                if (chon == sodong) chon = 0;
                Write(st[luuchon], x0, y0 + luuchon, YELLOW);
                Write(st[chon], x0, y0 + chon, CYAN);
                break;
            case 13: //phim ENTER
                ok = true;
                break;

            default:

                break;
        }
        if (ok) //Neu phim ENTER duoc nhan
        {
            switch (chon) {
                case 0:
                    system("cls");
                    baitap1();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 1:
                    system("cls");
                    baitap2();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;
                case 2:
                    system("cls");
                    baitap3();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;
                case 3:
                    system("cls");
                    baitap4();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 4:
                    system("cls");
                    baitap5();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;
                case 5:
                    system("cls");
                    baitap6a();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 6:
                    system("cls");
                    baitap6b();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 7:
                    system("cls");
                    baitap6c();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 8:
                    system("cls");
                    baitap6d();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 9:
                    system("cls");
                    baitap7();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 10:
                    system("cls");
                    baitap8();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;

                case 11:
                    system("cls");
                    baitap9();
                    getch();
                    Ve_menu(x0, y0, chon, sodong, st);
                    break;


                case end_index:
                    exit(0);

                default:
                    break;
            }
            ok = false; //tra lai trang thai ENTER chua duoc nhan
        }
    } while (ch != 27);//Nhan phim ESC de thoat khoi chuong trinh

    return 0;
}
