#include<bits/stdc++.h>
using namespace std;

// Thuat toan dijkstra tim duong di ngan nhat tu 1 dinh den s den moi dinh con lai tren do thi. 
// BFS tim duong di ngan nhat tren do thi khong co trong so
// Ap dung cho do thi co huong va vo huong, khong co trong so , O( (E + V) * logV ),

int n, m, s, t; // s la dinh bat dau
vector<pair<int,int>> adj[100001];

void inp(){
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++){
        int x, y, w;cin >> x >> y >> w;
        adj[x].push_back({y,w});
        //adj[y].push_back({x,w});
    }
}

const int INF = 1e9;
int pre[100001];
bool visited[100001]

void dijkstra(int s, int t){
    vector<int> d(n + 1, INF) ; // Xet gia tri mac dinh la  vo cung
    d[s] = 0;
    pre[s] = s;
    // Min heap ( hang doi uu tien ) hoac multi set
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    //{Khoang cach , dinh} sort theo khoang cach
    Q.push({0,s});
    while(Q.empty() == false){
        //Chon ra dinh co khoang cach tu s nho nhat
        pair<int, int> top = Q.top(); Q.pop();
        int kc = top.first;
        int u = top.second; 
        // Hoac dung mang visited 
        // if(visited[u] ) continue;
        // visited[u] = true;
        if(d[u] < kc) continue;
        // Relaxation : Cap nhap khoang cach nho hon
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                Q.push({d[v], v}); 
                pre[v] = u;  //cha cua v la u 
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << d[i] << " ";
    // }
    cout<< d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s ) break;
        t = pre[t];      
    }
    reverse(begin(path), end(path));
//    reverse(path.begin(), path.end());
    for(int x : path){
        cout << x << " ";
    }
}

int main(){
    inp();
    dijkstra(s, t);

    return 0;
}

// Di tu dinh 1 den dinh 5
//6 8 1 5 1 2 7 1 3 12 2 3 2 2 4 9 3 5 10 4 6 1 5 4 4 5 6 5