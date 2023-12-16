#include<bits/stdc++.h>
using namespace std;

//Do thi vo huong
//Ma tran ke (Nhap Dinh), Danh sach canh(Nhap Canh) , Danh sach ke(Nhap Dinh);
// int mt[n+1][n+1] mtk dung muc
	
int n,m;//n dinh, m canh
int a[1001][1001];
vector<int> adj[1001];


void mtk_dsc(){
	//Nhap mtk
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x;cin>>x;
			a[i][j]=a[j][i]=x;
		}
	}
	//Xuat mtk
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	//mtk_dsc cach 1
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i][j] == 1){
				cout<<i<<" "<<j<<endl;
			}
		}
	}	
	
	//mtk_dsc cach 2
	vector<pair<int,int>> edges;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] && i < j){
				edge.push_back({i,j});
			}
		}
		cout<<endl;
	}
	for(auto it: edges){
		cout<<it.first<<" "<<it.second<<endl;
	}
	
}

void mtk_dsk(){
	//Nhap mtk
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x;cin>>x;
			a[i][j]=a[j][i]=x;
		}
	}
	//Xuat mtk
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//mtk_dsk cach 1
	for(int i=1;i<=n;i++){
		cout<<i<<" : ";
		for(int j=1;j<=n;j++){
			if(a[i][j] == 1){
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	
	//mtk_dsk cach 2
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				adj[i].pushback(j);
			}
		}
		cout<<endl;
	}
	for(int i =1;i<n;i++){
		cout<<i<<" : ";
		for(auto it: adj[i]){
			cout<<it<<" "<<endl;
		}	
	}

		
}

void dsc_mtk(){
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		a[x][y] = a[y][x] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void dsc_dsk(){
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		a[x][y] = a[y][x] = 1;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	
	for(int i=1;i<=n;i++){
		cout<<y<<" : ";
		for(int x : adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

void dsk_mtk(){
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s,num;
		getline(cin,s);
		stringstream ss(s);
		while(ss >> num){
			a[i][stoi(num)] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
}

void dsk_dsc(){
	cin>>n;
	cin.ignore();
	for(int i=1;i<=n;i++){
		string s,num;
		getline(cin,s);
		stringstream ss(s);
		while(ss >> num){
			if(stoi(num) > i){
				edges.push_back({i, stoi(num)})
			}
		}
	}
	for(auto it : edges){
		cout<<it.first<<" "<<it.second<<endl;
	}		
}

int main(){
//	cin>>n>>m;
	
//	mtk_dsc();
//	mtk_dsk();
//	dsc_mtk();
//	dsc_dsk();
//	dsk_mtk();
//	dsk_dsc();
	return 0;
}
