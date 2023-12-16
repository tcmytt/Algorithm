#include<bits/stdc++.h>
using namespace std;

// dfs,bfs on grid
//Bai1: Dem so thanh phan lien thong
//Bai2: Kiem tra duong di 2 diem tren luoi
//Bai3: Tim so buoc toi thieu giua 2 o tren luoi
//Bai4: Truy vet duong di ngan nhat 2 diem tren luoi

int n,m;
char a[1001][1001]; //int a[1001][1001]
bool visited[1001][1001];

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void dfs(int i,int j){
	visited[i][j]=true;
	//Duyet cac dinh ke
	for(int k=0;k<4;k++){
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='x' && visited[i1][j1]==false){
			//&& visited[i1][j1]=false co the thay bang visited[i1][j1]=0 con visited[i][j]=true thay bang visited[i][j]='0'
			dfs(i1,j1);
		}
	}
}

void bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j] ='o';
	while(q.empty() == false){
		pair<int,int> top = q.front();
		q.pop();
	for(int k=0;k<4;k++){
		int i1 = top.first + dx[k];
		int j1 = top.second + dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]=='x'){
			//&& visited[i1][j1]=false co the thay bang visited[i1][j1]=0 con visited[i][j]=true thay bang visited[i][j]='0'
			q.push({i1,j1});
			a[i1][j1]='o';
		}
	}	
		
	}
}

void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	memset(visited,false,sizeof(visited));
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='x' && visited[i][j]==false){
//				dfs(i,j);
				bfs(i,j);
//				cout<<i<<" "<<j<<endl;
				cnt++;
			}
		}
	}
	cout<<cnt<<" thanh phan lien thong"<<endl;
	
}

int main(){
	inp();
	return 0;
}

