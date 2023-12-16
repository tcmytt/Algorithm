#include<bits/stdc++.h>
using namespace std;

// Loai bo dinh tru, canh cau lam tang so thanh phan lien thong cua do thi
// Loai bo dan dinh, neu tang lien thong thi no la dinh tru

//Brutal force:Dinh tru  O(V *(V+E)) ; Canh cau O(E *(V+E))
// Toi uu O(V + E)

int n,m;
vector <int> adj[1001]; 
bool visited[1001]; 

vector<pair<int,int>> dscanh;

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y;cin>>x>>y;
        adj[x].push_back(y); 
        adj[y].push_back(x);
        dscanh.push_back({x,y});
    }
    memset(visited , false, sizeof(visited));
}

void dfs(int u){
    visited[u] == true;
    for( int x : adj[u]){
        if(visited[x] == false){
            dfs(x);
        }
    }
}

void dinhtru(){
    int ans = 0;
    int tplt =0;
    
    for(int i = 1;i<=n;i++){
        if(visited[i] == false){
            tplt++;
            dfs(i);
        }
    }

    for(int i = 1;i<=n;i++){
        memset(visited , false, sizeof(visited));
        visited[i] == true;
        int dem = 0;
        for(int j =1;j<=n;j++){
            if(visited[j] == false){
                dem ++;
                dfs(j);
            }
        }
        if(dem>tplt){
            ans ++;
        }
    }
    cout << ans << endl;
}

// s -> t la canh ma ta khong xet
void dfs2(int u, int s, int t){
    visited[u] == true;
    for( int x : adj[u]){
        if((u == s && x == t) || (u == t && x == s)) continue;
        if(visited[x] == false){
            dfs2(x , s , t);
        }
    }
}

void canhcau(){
    int ans = 0;
    int tplt =0;
    
    for(int i = 1;i<=n;i++){
        if(visited[i] == false){
            tplt++;
            dfs(i);
        }
    }

    for(auto it : dscanh){
        int x = it.first, y =it.second;
        //Loai bo canh (x,y ) khoi do thi
        memset(visited , false, sizeof(visited));
        int dem = 0;
        for(int j =1;j<=n;j++){
            if(visited[j] == false){
                dem ++;
                dfs2(j,x,y);
            }
        }
        if(dem>tplt){
            ans ++;
        }
    }
    cout << ans << endl;
}

int main(){
    inp();
    dinhtru();
    return 0;
}