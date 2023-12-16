#include<bits/stdc++.h>
using namespace std;

//Dem so thanh phan lien thong / Do thi vo huong, connected component
// Y tuong: Dung dfs(bfs) chay roi danh dau da tham, for lap cac dinh dinh chua tham ++1


int n,m;
bool a[1001];
vector<int> b[1001];

void Nhap(){
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x); // Co huong thi bo dong nay di, Vo huong giu lai
	}
	
}

void DFS(int x){
	a[x] = true;
	cout<<x<<" ";
	for(auto c : b[x]){
		if(a[c] == false){
			DFS(c);
		}
	}
}


void BFS(int x){
	queue<int> q;
	q.push(x);
	a[x] = true;
	while(!q.empty()){
		int tmp = q.front();
		cout<<tmp<<" ";
		q.pop();
		for(auto c : b[tmp]){
			if(a[c]==false){
				q.push(c);
				a[c]=true;
			}
		}
	}
}

void countComponent(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==false){
			cnt++;
			DFS(i);
		}
	}
	cout<<endl<<cnt<<" Thanh phan lien thong ";
}
int main(){
	cin>>n>>m;
	Nhap();
	countComponent();
	return 0;
}
