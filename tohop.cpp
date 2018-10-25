using namespace std;
 
int a[100000] ;
int k , n ;
 
void printResult() { // hàm dùng để in một cấu hình ra ngoài
    for(int i = 1 ; i <=k ; i++) {
        cout<<a[i]<<" " ;
    }
    cout<<endl ;
}
void backtrack(int i ) { // hàm quay lui
    for(int j = a[i-1]+1 ; j<=n-k+i ; j++ ) { // xét các khả năng của j
        a[i] = j ; // ghi nhận một giá trị của j
        if(i==k) { // nếu cấu hình đã đủ k phần tử
            // in một cấu hình ra ngoài
            printResult() ;
        }
        else {
            backtrack(i+1) ; // quay lui
        }
 
    }
}
void toHop() { // hàm liệt kê các tổ hợp
    if(k>=0 && k <=n ) {
        a[0] = 0 ; // khởi tạo giá trị a[0]
        backtrack(1) ;
    }
    else {
        cout<<"Loi: khong thoa dieu kien 0<=k<=n "<<endl ;
    }
 
}
 
 
int main()
{
    cout<<"Nhan k va n: " ;
    cin>>k>>n ;
    toHop()  ;
    return 0;
}
