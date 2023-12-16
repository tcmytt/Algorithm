#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j-1]<a[j]){					//Sap xep Lon->Nho
				swap(a[j-1],a[j]);
			}
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
	
	bubbleSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
