#include<bits/stdc++.h>
using namespace std;

void inp(){

}

void VD1(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[1001];
        for(int i = 0 ; i < n; i++){
            cin>>a[i];
        }
        long long sum = 0;
        for(int i =0; i<k;i++){
            sum += a[i];
        }
        long long res = sum, idx = 0;
        for(int i =k; i < n; i++){
            sum = sum - a[i-k] + a[i];
            if( sum > res ){
                res = sum ; 
                idx = i- k + 1;
            }
        }
        cout<<res<<endl;
        for(int j = 0 ; j<k;j++){
            cout<<a[idx + j] << " ";
        }
    }
    cout<<endl;
    //1 10 3 2 1 3 5 4 8 6 1 5 1
}

int main(){
    VD1();
    return 0;
}