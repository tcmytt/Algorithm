#include<bits/stdc++.h>
using namespace std;

// Tron 2 day: day1[l,m], day2[m+1,r]

int merge(int a[], int l, int m, int r){
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i=0, j=0;
	int cnt=0;
	while( i < x.size() && j < y.size() ){
		if(x[i] <= y[j] ){
			a[l] = x[i];
			l++,i++;
		}else{
			cnt += x.size() - i;
			a[l] = y[j];
			l++,j++;
		}
	}
	while( i< x.size()){
		a[l]=x[i];
		l++;i++;
	}
	while( j< y.size()){
		a[l]=y[j];
		l++;j++;
	}
	return cnt;
}

int mergeSort(int a[], int l, int r){
	int dem =0;
	if( l<r ){
		int m= (l+r)/2;
		dem += mergeSort(a,l,m);
		dem += mergeSort(a,m+1,r);
		dem += merge(a,l,m,r);		
	}
	return dem;
}

int main(){
	int n=4;
	int a[n];
	srand(time(NULL));
	
	for(int i=0;i<n;i++){
		a[i]=rand() % 100;
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
	cout<<"Nghich The:"<< mergeSort(a, 0 , n-1)<<endl;
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
