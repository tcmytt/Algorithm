#include<bits/stdc++.h>
using namespace std;

//Do thi co huong lien thong manh Strongly connected component 
//Ap dung tim, tinh so lien thong manh(1 dinh den duoc 1 dinh bat ki)
//C1:Dung dfs cho tung canh roi kiem tra no co den duoc cac canh con lai khong(Do phuc tap cao)
//C2:Kosaraju chi can 2 lan dfs la kiem tra duoc:  O(V+E)
// Bc1: DFS tren G(Graphic) -> Luu thu tu duyet vao stack(sap xep topo) duyet xong dau tien o cuoi stack
// Bc2: Xay dung TG(TransperGraphic) 
// BC3: Pop dinh o bc1 va goi DFS tren TG

int n,m;
bool v[1001];
vector<int> adj[1001];
vector<int> r_adj[1001];
stack<int> st;

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}

void dfs1(int u){
	v[u]=true;
	for(int x : adj[u]){
		if(v[x]==false){
			dfs1(x);
		}
	}
	st.push(u);
	cout<<u<<" ";
}

void dfs2(int u){
	v[u]=true;
	cout<<u<<" ";
	for(int x : r_adj[u]){
		if(v[x]==false){
			dfs2(x);
		}
	}
}

void SCC(){
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			dfs1(i);
		}
	}
	cout<<endl;
	memset(v,false,sizeof(v));
	while(st.empty()==false){
		int top=st.top();st.pop();
		if(v[top]==false){
			dfs2(top);
			cout<<endl;
		}
	}
}

int main(){
	inp();
	SCC();
	return 0;
}
