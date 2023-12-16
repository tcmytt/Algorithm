#include<bits/stdc++.h>
using namespace std;
#define N 100005;
// Thường dùng vào tính tổng và đếm(VD: đếm nghịch thế)

int bit[N];
int getSum(int p) {
    int idx = p, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int main(){

    return 0;
}