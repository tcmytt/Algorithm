#include<iostream>
using namespace std;

//Lon->Nho

void insertionSort(int a[],int n){
	int pos,x;
	for(int i=0;i<n-1;i++){
		x=i;
		pos=i+1;
		while(a[pos]>a[pos-1] && pos>0){
			swap(a[pos],a[pos-1]);
			pos--;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	insertionSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
