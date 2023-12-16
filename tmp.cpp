#include <bits/stdc++.h>
using namespace std;

// vector<int> memo;

// git commit -m "first commit"

// int dq(int n){
//     if (n <= 1) {
//         return 1;
//     }

//     // Kiểm tra xem đã tính giai thừa cho n này chưa
//     if (memo[n] != 0) {
//         return memo[n];
//     }

//     // Nếu chưa tính, tính giai thừa và lưu vào memo
//     memo[n] = n * dq(n - 1);
//     return memo[n];
// }

int main(){
    int x;
    cin>>x;
    cout<<x;
    // int n = 5;
    // memo = vector<int>(n + 1, 0); // Khởi tạo memo với các giá trị ban đầu là 0
    // cout << "Giai thừa của " << n << " là: " << dq(n);
    return 0;
}
