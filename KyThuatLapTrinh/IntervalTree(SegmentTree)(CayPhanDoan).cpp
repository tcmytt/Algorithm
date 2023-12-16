#include<bits/stdc++.h>
using namespace std;

int a[]={0,1,2,5,8,7,4,6};
int t[4*10];

void build(int id,int l, int r){
    if(l==r) return t[id]=a[l], void();
    int m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2] + t[id*2+1] ;
}

int get(int id,int l, int r, int u, int v){
    if( r < u || l > v ) return 0;
    if( u <= l && r <= v ) return t[id];
    int m = (l+r)/2;
    int t1 = get(id*2,l,m,u,v);
    int t2 = get(id*2+1,m+1,r,u,v);
    return t1+t2;
}

void update(int id,int l, int r, int p, int val){
    if(p < l || p > r) return;
    if(l==r){
        a[p]=val;
        t[id] = a[p];
    } 
    int m = (l+r)/2;
    update(id*2,l,m,p,val);
    update(id*2+1,m+1,r,p,val);
    t[id] = t[id*2] + t[id*2+1];
}

int main(){
    int n=a.size() - 1 ;
    build(1,1,8);

    // Cach build bang update 
    // Chạy thu i = 0
    // for(int i=1; i<=n; i++){
    //     cin>>a[i];
    //     update(1,1,n,i,a[i]);
    // }

    int p=1,val=10; // p la vi tri can update, val la gia tri can update
    update(1,1,n,p,val)
    return 0;
}