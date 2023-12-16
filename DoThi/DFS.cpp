#include<bits/stdc++.h>
using namespace std;

// 8 1 2 1 3 1 4 2 5 2 6 3 7 4 8 7 9
// O(V+E), DFS: Depth First Search
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

void DFS(int x){
	a[x] = true;
	cout<<x<<" ";
	for(auto c : b[x]){
		if(a[c] == false){
			DFS(c);
		}
	}
}

int main(){
	cin>>m;
	Nhap();
	DFS(1);
	return 0;
}
