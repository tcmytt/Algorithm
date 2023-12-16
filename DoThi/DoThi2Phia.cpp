#include<bits/stdc++.h>
using namespace std;

// Do thi 2 phia(Do thi luong phan) la do thi trong do tap cac dinh chia thanh 2 tap khong giao nhau
// thoa man dieu kien khong co canh noi 2 dinh bat ki thuoc cung 1 tap
// Kiem tra do thi co phai do thi Luong phan khong?
// Nen dung bfs do no kiem tra gan ke xem co cung mau khong?

int n,m;
vector <int> ke[1001];
int color[1001];

void nhap(){
    cin>>n>>m;
    for(int i = 0 ;i<m;i++){
        int x,y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(color, -1 , sizeof(color));
}

// 0 : RED ; 1 : BLUE
bool bfs(int u){
    queue <int> q;
    q.push(u);
    color[u] = 0;
    while(q.empty() == false){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(color[x]== -1){
                // color v la 1 thi color x la 0, la 0 thi la 1
                color[x] = 1 - color[v];
                q.push(x);
            }else if(color[x] == color [v]) {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int u, int par){
    color[u] = 1 - color[par];
    for(int v : ke[u]){
        if(color[v] == -1){
            if(dfs(v,u) == false) return false;
        }else if(color[v]  == color [u]) return false;
    }
    return true;
}

int main(){
    bool check = true;
    nhap();

//    color[0] == 1;

    for(int i =1;i<=n;i++){
        if(color[i] == -1){
            // \dfs(i,0);
            if(!bfs(i)){
                check =false; break;
                // Neu 1 lien thong ko la 2 phia thi ca do thi se ko la 2 pha
            }
        }
    }
    if(check){
        cout<<"Do thi lien thong 2 phia ";
    }else{
        cout<<"Do thi khong lien thong 2 phia ";
    }
    return 0;
}