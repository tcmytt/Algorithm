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
int d[1001][1001]; // d[i][j] luu so buoc di tu o bat dau toi o i,j
pair<int,int> p[1001][1001];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void bfs(int i,int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	a[i][j] ='x';
	d[i][j] =0;
//	cout<<i<<" "<<j<<endl;
	while(q.empty() == false){
		pair<int,int> top = q.front();
		q.pop();
	for(int k=0;k<4;k++){
		int i1 = top.first + dx[k];
		int j1 = top.second + dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]!='x'){
//			cout<<i1<<" "<<j1<<endl;
//			cha cua i1,j1 la first,second
			p[i1][j1]={top.first,top.second};
			d[i1][j1] = d[top.first][top.second] + 1;
			q.push({i1,j1});
			if(a[i1][j1]=='E') return;
			a[i1][j1]='x';
		}
	}	
		
	}
}

void inp(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='S'){
				x1=i;y1=j;
			}
			if(a[i][j]=='E'){
				x2=i;y2=j;
			}			
		}
	}
	memset(visited,false,sizeof(visited));
//	cout<<x1<<" "<<y1<<" | "<<x2<<" "<<y2<<endl;
	bfs(x1,y1);
	int x2tmp=x2,y2tmp=y2;
	if(d[x2][y2]==0){
		cout<<"Khong co duong di ";
	}else{
		cout<<"Co duong di "<<d[x2][y2]<<" la khoang cach ngan nhat "<<endl;
			//Truy vet
		vector<pair<int,int>> path;
		while(x2!=x1 || y2!=y1){
//			cout<<x2<<" "<<y2<<endl;
			path.push_back(p[x2][y2]);
			auto tmp = p[x2][y2];
			x2=tmp.first;
			y2=tmp.second;
		}
//		path.push_back({x1,y1});
		reverse(path.begin(),path.end());
		path.push_back({x2tmp,y2tmp});
		for(auto x : path){
			cout<<x.first<<" "<<x.second<<endl;
		}		
	}
	

	
}

int main(){
	inp();
	return 0;
}
// 4 4 S x x x o o x x o o o x E x x x
// 4 4 x S o o x o o o o o o o o o o E
