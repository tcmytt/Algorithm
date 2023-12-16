#include<bits/stdc++.h>
using namespace std;

//O(logn)
//Dung cho du lieu da sap xep

bool BinarySearch(int a[], int n, int x){
	int l = 0,r = n-1;
	while( l <= r){
		int m =(l+r) /2;
		if(a[m]==x){
			return true;
		}
		else if(a[m] < x){
			l = m+1;
		}else if(a[m] < x){
			r = m-1;
		}
	}
	return false;
}

int main(){
	int n=10;
	int x=8;
	int a[n];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		a[i]=rand() % 10;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	sort(a,a+n);
	//Ham binary search san co
	binary_search(a,a+n,x);
	if(BinarySearch(a,n,x)){
		cout<<"Tim thay";
	}else{
		cout<<"Khong thay";
	}
	return 0;
}
