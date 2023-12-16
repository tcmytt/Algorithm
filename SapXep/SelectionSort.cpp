#include<iostream>
using namespace std;

void selectionSort(int a[],int n){
	int tmp=0;
	for(int i=0;i<n;i++){
		tmp =i;
		for(int j=i+1;j<n;j++){
			if(a[tmp]<a[j]){					//Sap xep Lon->Nho
				tmp=j;
			}
		}
		swap(a[i],a[tmp]);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	selectionSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
