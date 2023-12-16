#include<bits/stdc++.h>
using namespace std;

//Kiem tra chu trinh tren do thi vo huong : Co canh nguoc la co chu trinh
//Nen dung dfs cho vo huong

int n,m,s,e;//start - end dung de truy vet
bool v[1001];
vector<int> adj[1001];
int parent[1001];

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

//par = parent
//bool dfs(int u, int par){
//	v[u]=true;
//	for(int x : adj[u]){
//		if(v[x]==false){
//			if(dfs(x,u)) return true;
//		}
//		if(v[x]==true && x!=par){ // hoac else if(x!=par)
//			return true;
//		}
//	}
//	return false;
//}

bool dfs(int u){
	v[u]=true;
	for(int x : adj[u]){
		if(v[x]==false){
			parent[x]=u;
			if(dfs(x)) return true;
		}
//		if(v[x]==true && x!=parent[u]) hoac
		else if(x!=parent[u]) 
		{ 
			s =x;e =u;
			return true;
		}
	}
	return false;
}

bool bfs(int u){
	queue <int> q;
	v[u]=true;
	q.push(u);
	while(q.empty()==false){
		int top = q.front();
		q.pop();
		for(int x : adj[top]){
			if(v[x]==false){
				q.push(x);
				v[x]=true;
				parent[x] = u;
			}else if(x != parent[top]){
				s = x; e = top;
				return true;
			}
		}
	}
	return false;
}

//7 6 1 2 2 3 2 4 3 6 6 7 7 3 

int main(){
	inp();
	//Goi 1 lan neu do thi da lien thong
//	if(dfs(1,0)){
//		cout<<"Co chu trinh ";
//	}else{
//		cout<<"Khong co chu trinh ";
//	}
	//Nhieu thanh phan lien thong goi nhieu lan
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			if(dfs(i)){
				cout<<"Co chu trinh ";
				vector<int> path;
				path.push_back(s);
				while(e!=s){
					path.push_back(e);
					e=parent[e];
				}
				path.push_back(s);
				reverse(path.begin(),path.end());
				for(int x : path){
					cout<<endl<<x<<" ";
				}
				return 0;
			}else{
				cout<<"Khong co chu trinh ";
				return 0;
			}
		}
	}
	
	//bfs ko truy vet chu trinh nhu tren duoc
//	for(int i=1;i<=n;i++){
//		if(v[i]==false){
//			if(bfs(i)){
//				cout<<"Co chu trinh ";
//				return 0;
//			}else{
//				cout<<"Khong co chu trinh ";
//				return 0;
//			}
//		}
//	}
	return 0;
}


