#include<bits/stdc++.h>
using namespace std;

//Tim duong di tren do thi khong co trong so, BFS dua ra duong di toi uu
//Truy vet duong di, bfs toi uu
// 8 5 1 2 1 3 2 4 2 5 6 7

//Neu kiem tra 2 dinh co duong di hay khong ta kiem tra xem 2 dinh co trong cung 1 lien thong hay khong la duoc, khong can moi lan deu kiem tra lai

int n,m;
int s,e;//Dinh bat dau va ket thuc
bool a[1001];
vector<int> b[1001];
int p[1001]; //Mang parent

void Nhap(){
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x); // Co huong thi bo dong nay di, Vo huong giu lai
	}
	
}

void DFS(int x){
	a[x] = true;
	for(auto c : b[x]){
		if(a[c] == false){
			//cha cua c la x;
			p[c]=x;
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
		//cout<<tmp<<" ";
		q.pop();
		for(auto c : b[tmp]){
			if(a[c]==false){
				q.push(c);
				a[c]=true;
				p[c] = tmp;
			}
		}
	}
}

void path(){
//	DFS(s);
	BFS(s);
	if(a[e]==false){
		cout<<"Khong co duong di ";
	}else{
		//Truy vet
		vector<int> Path;
		//Bat dau tu dinh t
		while(e != s){
			Path.push_back(e);
			//Lan nguoc lai
			e = p[e];
		}
		Path.push_back(s);
		reverse(Path.begin(),Path.end());
		for(int x : Path){
			cout<<x<<" ";
		}
	}
}

int main(){
	cin>>n>>m;
	Nhap();
	cin>>s>>e;
	path();
	return 0;
}
