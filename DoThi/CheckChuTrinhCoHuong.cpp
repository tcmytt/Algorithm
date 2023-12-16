#include<bits/stdc++.h>
using namespace std;

//Kiem tra chu trinh tren do thi co huong : 
//Co 3 trang thai white = 0 chua duyet , gray = 1 dang duyet , black =2 da duyet xong
//Nen dung dfs ; Co the dung disjoint set

int n,m,s,e;//start - end dung de truy vet
int color[1001]; // 
vector<int> adj[1001];
int parent[1001];
int degree[1001];

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		degree[y]++;
	}
}

bool dfs(int u){
	color[u]=1; // mau xam
	for(int x : adj[u]){
		if(color[x]==0){ // mau trang
			parent[x]=u;
			if(dfs(x)) return true;
		}
		else if(color[x]==1)  // ton tai canh nguoc
		{ 
			s =x;e =u;
			return true;
		}
	}
	color[u]=2;
	return false;
}

//can tinh ban bac vao
bool kahn(){
	queue<int> q;
	for(int i =1;i <=n;i++){
		if(degree[i]==0){
			q.push(i);
		}
	}
	int cnt = 0;
	while(q.empty()==false){
		int top = q.front();
		q.pop();
		cnt++;
		for(int x : adj[top]){
			degree[x]--;
			if(degree[x]==0){
				q.push(x);
			}
		}
	}
	if(cnt==n){
		return false;
	}
	return true;
}

//7 7 1 2 1 5 2 3 3 6 4 2 6 7 3 7  KO
//7 7 1 2 1 5 2 3 3 6 4 2 6 7 7 3  CO

int main(){
	inp();
//	for(int i=1;i<=n;i++){
//		if(color[i]==0){
//			if(dfs(i)){
//				cout<<"Co chu trinh ";
//				vector<int> path;
//				path.push_back(s);
//				while(e!=s){
//					path.push_back(e);
//					e=parent[e];
//				}
//				path.push_back(s);
//				reverse(path.begin(),path.end());
//				for(int x : path){
//					cout<<endl<<x<<" ";
//				}
//				return 0;
//			}else{
//				cout<<"Khong co chu trinh ";
//				return 0;
//			}
//		}
//	}
	
	if(kahn()){
		cout<<"Co";
	}else{
		cout<<"Khong";
	};
	return 0;
}


