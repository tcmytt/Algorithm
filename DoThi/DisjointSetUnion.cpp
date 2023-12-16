#include<bits/stdc++.h>
using namespace std;

//Cau truc du lieu cac tap hop roi nhau | Disjoint Set Union DSU | Union Find
//2 Thao ta chinh: Gop 2 phan tu, Kiem tra phan tu thuoc tap hop nao

int n;
int parent[1001];
int size[1001];

void makeSet(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

int find(int v){
	if(v==parent[v]){
		return v;
	}else{
		return parent[v]=find(parent[v]);
	}
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a != b){
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b] = a;//Do size a lon hon
		size[a]+=size[b];
	}
}


int main(){
	
	return 0;
}
