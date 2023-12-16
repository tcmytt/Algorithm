#include<iostream>
#include<time.h>
using namespace std;

////O(nlogn)
// 8 2 7 3 6 9 0 1 5

// MaxHeap la sap xep ang dan, MinHeap giam dan
/*
	Binary tree:
	- Bat dau tu 1 -> n; x la vi tri; h la so bac
	+ Con trai : 2x; Con Phai : 2x+1; Cha [x/2]; Cay nhi phan day du co 2^h -1 nut; Cay nhi phan hoan chinh : Ngieng ve ban trai
	- Bat dau tu 0 -> n; Con trai : 2x+1; Con phai 2x+2; Cha : (x-1)/2
	Heap la cay nhi phan hoan chinh va thang cha lon hon con ben trai va con ben phai(Max Heap), Nho hon thi la Min Heap 
	prioQueue la heap
	- Heapify la thao tac xay dung max(min) heap
	- (n/2) - 1 : la phan tu khong phai la cuoi cung
*/
//void heapify(int a[],int n, int i){
//	int max = i;
//	int l =2*i + 1;
//	int r =2*i + 2;
//	
//	if(l<n && a[l] > a[max]){
//		max = l;
//	}
//	
//	if(r<n && a[r] > a[max]){
//		max =r;
//	}
//	if(max != i){
//		swap(a[i],a[max]);
//		heapify(a,n,max);
//	}
//	
//}

void heapify(int a[],int n, int i){
	int min = i;
	int l =2*i + 1;
	int r =2*i + 2;
	
	if(l<n && a[l] < a[min]){
		min = l;
	}
	
	if(r<n && a[r] < a[min]){
		min =r;
	}
	if(min != i){
		swap(a[i],a[min]);
		heapify(a,n,min);
	}
	
}

void heapSort(int a[],int n){
	//Xay max,min heap
	for(int i=n/2 -1 ;i >= 0;i--){
		heapify(a,n,i);
	}
	//heapsort
	for(int i=n-1;i >= 0; i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
	
}

void random(int a[],int n){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		a[i]=rand() % 500;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	heapSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
