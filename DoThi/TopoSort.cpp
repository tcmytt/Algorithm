#include<bits/stdc++.h>
using namespace std;

//Thuat toan sap xep topo tren do thi co huong, khong co chu trinh, giong cay: Neu co duong noi tu dinh u toi v thi dam bao u dung truoc v
//Ap dung vao cac bai toan cac node co moi quan he truoc sau. VD: Phai hoc mon Ky thuat lap trinh truoc Cau truc du lieu giai thuat
//7 7 1 2 2 3 2 4 3 5 4 5 1 6 7 6

int n,m;
vector<int> adj[1001];
bool v[1001];
vector<int> topo;
int in[1001]; //Kahn: Tinh ban bac vao

void inp(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);
		in[y]++;
	}
}

void dfs(int u){
	v[u]=true;
	for(int x : adj[u]){
		if(v[x]==false ){
			dfs(x);
		}
	}
	topo.push_back(u);
}

//Thuat toan kahn( Xoa dan dinh)
//Neu do thi co huong co chu trinh thi se khong du dinh(Ung dung tim chu trinh tren do thi co huong)
void kahn(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i); 
		}
	}
	while(q.empty()==false){
		int u = q.front();
		q.pop();
		topo.push_back(u);
		for(int x : adj[u]){
			in[x]--;
			if(in[x]==0){
				q.push(x);
			}
		}
	}
	for(int x : topo){
		cout<<x<<" ";
	}
}

int main(){
	inp();
	kahn();
//	for(int i=1;i<=n;i++){
//		if(v[i]==false){
//			dfs(i);
//		}
//	}
//	reverse(topo.begin(),topo.end());
//	for(auto x: topo){
//		cout<<x<<" ";
//	}
	return 0;
}
