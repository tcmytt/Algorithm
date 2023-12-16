#include<bits/stdc++.h>
using namespace std;

// 8 1 2 1 3 1 4 2 5 2 6 3 7 4 8 7 9
// O(V+E), BFS: Breadth First Search
int m;
bool a[1001];
vector<int> b[1001];

void Nhap(){
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x); // Co huong thi bo dong nay di, Vo huong giu lai
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

int main(){
	cin>>m;
	Nhap();
	BFS(1);
	return 0;
}
