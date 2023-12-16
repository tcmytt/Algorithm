#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *nxt;
	Node *pre;
};

typedef Node* node;

node makeNode(int x){
	node tmp = new Node();
	tmp->data = x;
	tmp->nxt = NULL;
	tmp->pre = NULL;
	return tmp;
}

bool empty(node a){
	return a==NULL;
}

int size(node a){
	int cnt =0;
	while(a!=NULL){
		cnt++;
		a=a->nxt;
	}
	return cnt;
}

void insertFirst(node& a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
		a=tmp;
	}else{
		a->pre = tmp;
		tmp->nxt = a;		
		a = tmp;
	}
}

void insertLast(node& a, int x){
	node tmp = makeNode(x);
	if(a==NULL){
		a=tmp;
	}else{
		node p = a;
		while(p->nxt != NULL){
			p=p->nxt;
		}
		p->nxt = tmp;
		tmp->pre = p;
	}
}

void insertMiddle(node& a,int x,int pos){
	int n = size(a);
	if(pos == 1) insertFirst(a,x);
	if(pos == n+1) insertLast(a,x);
	if(pos > 1 && pos < n+1){
		node p = a;
		for(int i =1 ;i<pos ;i++ ){
			p = p->nxt;
		}
		node tmp = makeNode(x);
		p->pre->nxt = tmp;
		tmp->pre = p->pre;
		tmp->nxt = p;
		p->pre =tmp;
	}
}

void deleteFirst(node& a){
	if(a==NULL){
		return;
	}else{
		node p = a;
		a = a->nxt;
		a->pre = NULL;
		delete p;
	}
}

void deleteLast(node& a){
	if(a==NULL){
		return;
	}else{
		node p ;
		node q =a;
		while(q->nxt != NULL){
			p = q;
			q = q->nxt;
		}
		p->nxt=NULL;
		delete q;
	}	
}

void deleteMiddle(node& a, int pos){
	int n = size(a);
	if(pos == 1) deleteFirst(a);
	if(pos == n) deleteLast(a);
	if(pos > 1 && pos < n){
		node p = a;
		for(int i=1;i<pos;i++){
			p = p->nxt;
		}
		p->pre->nxt = p->nxt;
		p->nxt->pre = p->pre;
		delete p;
	}	
}

void showList(node a){
	cout<<endl;
	cout<<"List : ";
	while(a != NULL){
		cout<< a->data<<" ";
		a = a->nxt;
	}
	cout<<endl<<endl;;
}

void sortList(node& a){
	for(node p =a; p->nxt !=NULL; p=p->nxt){
		for(node q =p; q != NULL; q=q->nxt){
			if(p->data > q->data){
				swap(p->data,q->data);
			}
		}
	}
}

int main(){
	node a =NULL;
	while( 1){
		cout<<"--------------------------------------------------"<<endl;
		cout<<"1.Khoi tao danh sach lien ket don "<<endl;
		cout<<"2.Them 1 phan tu o dau "<<endl;
		cout<<"3.Them 1 phan tu o giua "<<endl;
		cout<<"4.Them 1 phan tu o cuoi "<<endl;
		cout<<"5.Xoa 1 phan tu o dau "<<endl;
		cout<<"6.Xoa 1 phan tu o giua "<<endl;
		cout<<"7.Xoa 1 phan tu o cuoi "<<endl;
		cout<<"8.Sap xep danh sach tang dan "<<endl;
		cout<<"9.Thoat tien trinh "<<endl;
		cout<<"Nhap phuong an lua chon : ";
		int chon,x,pos;
		cin>>chon;
		cout<<"--------------------------------------------------"<<endl<<endl;
		
		if(chon == 1){
			int n;
			cout<<"Nhap vao n phan tu ";cin>>n;
			int arr[n];
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			for(int i = 0;i<n;i++){
				insertLast(a,arr[i]);
			}
			showList(a);
		}
		if(chon == 2){
			cout<<"Nhap phan tu can them ";cin>>x;
			insertFirst(a,x);
			showList(a);
		}
		if(chon == 3){
			cout<<"Nhap phan tu can them ";cin>>x;
			cout<<"Nhap vi tri chen ";cin>>pos;
			insertMiddle(a,x,pos);
			showList(a);
		}
		if(chon == 4){
			cout<<"Nhap phan tu can them ";cin>>x;
			insertLast(a,x);
			showList(a);
		}
		if(chon == 5){		
			deleteFirst(a);
			showList(a);
		}
		if(chon == 6){
			cout<<"Nhap vi tri can xoa ";cin>>pos;			
			deleteMiddle(a,pos);
			showList(a);
		}
		if(chon == 7){
			deleteLast(a);
			showList(a);
		}
		if(chon == 8){
			cout<<"Sau khi sap xep :"<<endl;
			sortList(a);
			showList(a);
		}
		if(chon == 9){
			break;
		}
		
	}
	cout<<"----------------Chuong trinh ket thuc----------------"<<endl<<endl;
	return 0;
}
