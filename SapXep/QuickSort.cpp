#include<iostream>
using namespace std;

//Lon->Nho
//O(nlogn) Te nhat n2

void quickSort(int a[],int l,int r){
	int i=l;
	int j=r;
	int k= a[(i+j)/2];
	do{
		while(a[i]>k) i++;
		while(a[j]<k) j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<j);
	if(l<j){
		quickSort(a,l,j);
	}
	if(i<r){
		quickSort(a,i,r);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	quickSort(a,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
