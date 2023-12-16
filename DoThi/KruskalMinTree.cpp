#include <bits/stdc++.h>
using namespace std;

//MST: Minimum spanning tree
//Do thi co trong so, cay khung la cay khong co chu trinh, khong lien thong
//Cay khung nho nhat la tong trong so qua cac dinh nho nhat,n dinh
//Bc1: Sap xep cac canh tang dan ve trong so
//Bc2: Them cac cap canh lan luot vao cay khung moi, neu cap canh khong tao thanh chu trinh thi lay
// Cach kiem tra neu cap canh khong tao thanh chu trinh thi lay dung DisJointSet

int n,m;
int parent[1001],sz[1001];

struct edge{
    int u,v;
    int w;
    edge(int x,int y,int z){
        u=x;
        v=y;
        w=z;
    }
};

vector<edge> canh;

void make_Set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int v){
    if(v==parent[v]){
        return v;
    }else return parent[v]=find(parent[v]);
}

bool Union(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }else{
        if( sz[x] < sz[y] ){
            swap(x,y);
        }
        parent[y]=x;
        sz[x] += sz[y];
    }
    return true;
}

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        edge e = edge(x,y,w);
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b){
    // if(b.w > a.w) return true;
    // else return false;
    return b.w > a.w;
}

void kruskal(){
    //Tao cay khung rong, tong trong so = 0
    vector<edge> mst;
    int d=0;
    //sort danh sach canh tang dan
    sort(canh.begin(), canh.end(),cmp);
    //Lap tat ca cac canh
    for(int i=0;i<m;i++){
        if(mst.size() == n-1 ) break; // Nhet du dinh vao cay khung roi thi dung
        edge e = canh[i]; //Chon canh e la canh nho nhat
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d+= e.w;
        }
    }
    //Tra ve ket qua
    if(mst.size() != n-1 ){
        cout<<"Do thi khong lien thong! \n ";
    }else{
        cout<<"MST : "<<d <<endl;
        for(auto tmp : mst){
            cout<< tmp.u <<" "<< tmp.v<<" "<<tmp.w<<endl;
        }
    }
}

int main(){
    inp();
    make_Set();
    kruskal();            
    return 0;
}

// 6 9 1 2 12 1 3 4 2 3 1 2 4 5 2 5 3 3 5 2 4 5 3 4 6 10 5 6 8
// 6 8 1 2 7 1 3 2 1 6 1 2 3 3 2 4 5 3 4 2 3 5 9 5 6 1
