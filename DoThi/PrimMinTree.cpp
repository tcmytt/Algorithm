#include<bits/stdc++.h>
using namespace std;

//Tim cay khung cuc tieu
// Bc1: Khoi tao V, V(MST) -> dua vao V(MST) 1 dinh u , xoa dinh u khoi v
// Bc2: Lap den khi V rong : Lay ra cap canh (u,v) nho nhat : u thuov V, v thuoc V(MST); 
// dua v vao V(MST) xoa v khoi V
// Cach lay cap canh nho nhat dung PriorityQueue va khong dung

struct canh{
    int x,y,w;
};

int n,m;
vector <pair<int,int>> adj[1001]; // Luu cap canh x,y voi trong so la w;
bool used[1001]; //used[i] = true : i thuoc V(MST); used[i] = false i thuoc V

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y, w;cin>>x>>y>>w;
        adj[x].push_back({y,w}); //Gia tri vector adj[x] la pair {y,w}
        adj[y].push_back({x,w});
    }
    memset(used , false, sizeof(used));
}

void prim1(int u){
    vector<canh> MST;// Cay khung
    int d=0; // tong trong so
    used[u] = true; // Dua u vao MST
    while(MST.size() != n-1){
        //e = (x,y) : canh ngan nhat co x thuoc V va y thuoc V(MST)
        int min_w = INT_MAX;
        int X,Y; // luu 2 dinh cua canh e
        for(int i=1; i<=n;i++){
            // Neu dinh i thuoc V(MST)
            if(used[i]==true){
                //duyet dinh ke cua dinh i
                for(pair<int,int> it : adj[i]){
                    int j=it.first , trongso = it.second;
                    if( used[j]==false && trongso < min_w ){
                        min_w = trongso;
                        X=j;Y=i; 
                    }
                }
            }
        }
        MST.push_back({X,Y,min_w});
        d += min_w;
        used[X]=true; // cho X vao V(MST), loai X khoi V
    }
    cout<<"MST : "<<d<<endl;
    for(canh e : MST){
        cout<<e.x<<" "<<e.y<<" "<<e.w<<endl;
    }
}

//Dung min heap, prioty queue


void prim2(int u){
    // mang parent va d chi can khi can luu gia tri cay khung, khong can khi chi can luu chieu dai cay khung
    int parent[1001], d[1001];
    //Tao Min Heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;
    vector<canh> MST;
    int res  =0;
    Q.push({0,u});
    while(Q.empty()==false){
        pair<int,int> top = Q.top(); Q.pop();
        //De trong so len tren de PriorityQueue no sap xep theo trong so
        int trongso = top.first, dinh = top.second ;

        //Khi dinh da thuoc V(MST) thi khong xet nua
        if(used[dinh] == true) continue; 

        res += trongso;
        used[dinh]=true;
        //Dung de bo truong hop dau tien do u dau tien khong co cha 
        if(u!= dinh){
            MST.push_back({dinh,parent[dinh], trongso});
        }

        //Duyet tat ca cac dinh ke
        for(auto it : adj[dinh]){
            int y= it.first, w= it.second;
            if(used[y] == false && w < d[y]){
                Q.push({w,y}); d[y] = w;
                parent[y] = dinh;
            }
        }
    }
    cout<< res <<endl;
    for(auto it : MST){
        cout<<it.x<<" "<<it.y<<" "<< it.w << endl;
    }
}

int main(){
    inp();
    prim1(1);

    return 0;
}
//6 9 1 2 12 1 3 4 2 3 1 2 4 5 2 5 3 3 5 2 4 5 3 4 6 10 5 6 8