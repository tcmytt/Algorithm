#include<bits/stdc++.h>
using namespace std;

// dfs,bfs on grid
//Bai1: Dem so thanh phan lien thong
//Bai2: Kiem tra duong di 2 diem tren luoi
//Bai3: Tim so buoc toi thieu giua 2 o tren luoi
//Bai4: Truy vet duong di ngan nhat 2 diem tren luoi

int n,m,x1,y1,x2,y2;//x1,y1,x2,y2 toa do diem bat dau va ket thuc S va E, o co duong di x khong co duong di
char a[1001][1001]; //int a[1001][1001]
bool visited[1001][1001];

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool dfs(int i,int j){
	cout<<i<<" "<<j<<endl;
	if(a[i][j]=='E'){
		return true;
	}
	a[i][j]='x';
	//Duyet cac dinh ke
	for(int k=0;k<4;k++){
		int i1 = i+dx[k];
		int j1 = j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] != 'x'){
			if(dfs(i1,j1)) return true;
		}
	}
	return false;
}

bool bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j] ='x';
	while(q.empty() == false){
		pair<int,int> top = q.front();
		q.pop();
	for(int k=0;k<4;k++){
		int i1 = top.first + dx[k];
		int j1 = top.second + dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]!='x'){
			q.push({i1,j1});
			if(a[i1][j1]=='E'){
				return true;
			}
			a[i1][j1]='x';
		}
	}	
		
	}
	return false;
}

void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='S'){
				x1=i;y1=j;
			}
//			if(a[i][j]=='E'){
//				x2=i;y2=j;
//			}			
		}
	}
	memset(visited,false,sizeof(visited));
	if(bfs(x1,y1)){
		cout<<"co duong di "<<endl;
	}else{
		cout<<"Khong co duong di "<<endl;
	}
	
}

int main(){
	inp();
	return 0;
}
// 4 4 S o o x x o x o x o x x x x x E
