#include<bits/stdc++.h>
using namespace std;

// Xay dung dua tren quy hoach dong
// f[i][j] : So nho nhat trong doan bat dau tu i, va co do dai 2^j
// f[i][j] = min( f[i][j-1], f[i+ (2^j-1)][j-1] ) ma ta co (2^j-1) = 1<<j-1
// Tuong duong f[i][j] = min( f[i][j-1], f[i+ (1<<j-1)][j-1] )
// Note : (2^j-1) 2 mu cua (j -1); 1<<j-1 phep tru do uu tien cao hon nen j-1 thuc hien truoc roi 1<<j-1

// 2^20 > 10^6
// 8 5 2 4 3 1 7 6 8
#define maxn 100
int n, a[maxn], f[maxn][22];

int main(){

    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i], f[i][0] = a[i];

    for(int j =1; (1<<j) <= n; j++) {
        // i+(1<<j)-1 <= n co the bo -1 phan lon truong hop se khong sai  
        for(int i=1; i+(1<<j)-1 <= n; i++) {
            f[i][j] = min( f[i][j-1], f[i+ (1<<j-1)][j-1] );
            cout<<"i:"<<i<<", j:"<<j<<", f[i][j]:"<< f[i][j]<<" \n";
        }
    }

    for(int i =1;i<=n;i++) {
        for(int j =0; (1<<j) <= n; j++) {
            //cout<<"i:"<<i<<", j:"<<j<<", f[i][j]:"<< f[i][j]<<" \n";
        }
    }
    return 0;
}

