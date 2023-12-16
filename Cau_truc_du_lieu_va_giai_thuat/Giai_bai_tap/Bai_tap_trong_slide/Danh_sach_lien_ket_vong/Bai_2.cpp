#include<iostream>
using namespace std;

typedef struct node {
    int info;
    struct node* next;
} NODE;

typedef NODE* NodePtr;
NodePtr pList;

void Init(NodePtr &pList) {
    pList = NULL;
}
int InEmpty(NodePtr pList) {
	return (pList == NULL);
}

void Insert_Last(NodePtr &pList, int x) {
    NodePtr node;
    node = new NODE;
    node->info = x;
    if(pList == NULL) {
		pList = node;
		pList->next = pList;
    }
	else {
		node->next = pList->next;
		pList->next = node;
		pList = node;
    }
}

void nhapds(NodePtr &pList) {
	int n;
	cout << "Nhap so node cua danh sach: ";
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cout<<"Nhap node thu " << i << ": ";
		cin >> x;
		Insert_Last(pList, x);
	}
}

void ShowNode(NodePtr q) {
	cout << q->info<<"\t";
}

void ShowList(NodePtr pList) {
    NodePtr p;
    if(pList == NULL)
    return;
    p=pList->next;
    do {
		ShowNode(p);
		p = p->next;
	} while(p!= pList->next); 
}

void Insert_Before(NodePtr &pList, NodePtr &p, int x) {
	NodePtr node;
	node = new NODE;
	node->info = x;
	if(p == NULL) {
		return;
	}
	else {	
		NodePtr q = pList->next;
		while(q->next != p)
		{
			q = q->next;
		}
		q->next = node;
		node->next = p;
	}
}
void DeleteLast (NodePtr &pList) {
	NodePtr p; 
	if (pList == NULL) 
	return;
	else {
		if (pList == pList->next) {
			delete pList;
			pList = NULL;
		}
		else {
			p = pList;
			NodePtr q = pList -> next;
			while ( q -> next != pList)
			q = q -> next;
			q -> next = pList -> next;
			pList = q;
			delete p;
		}
	}
}

void Delete_After(NodePtr &pList, NodePtr &p) {
	NodePtr q;
	if(p->next == pList->next) {
		cout <<"Khong the xoa node nay"<<endl;
	}
	else {
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

void Mod_5(NodePtr pList) {
    NodePtr p = pList->next;
    do {
		p = p->next;
		if(p->info % 5 == 2) {
			cout<<p->info<<"\t";
		}
	} while(p!= pList->next); 
}

int main(){
	NodePtr pList;
	Init(pList);	
	nhapds(pList);	
	cout<<"Danh sach da nhap la: "<<endl;
	ShowList(pList);
	NodePtr p = pList->next;
	int x, k;
	cout<<"\n-Nhap gia tri node bo sung truoc node p: "; cin>>x;
	cout<<"\n Nhap node thu p: ";cin>>k;
	for(int i = 1;i < k; i++) {
        p= p->next;
	}
	cout<<"\n Node sau khi bo xung gia tri x truoc nut thu p :"<<endl;
	Insert_Before(pList,p,x);
	ShowList(pList);
	NodePtr q = pList->next;
	int y;
	cout<<"\n-Moi ban nhap node thu p: "; cin>>y;
	
	for(int i = 1;i < y; i++)
    {
        q= q->next;
	}
	cout<<"\n-------Loai bo node sau node p-------"<<endl;
	Delete_After(pList,q);
	ShowList(pList);
	cout<<"\n Cac node chia 5 du 2 trong danh sach la: "<<endl;
	Mod_5(pList);
	return 0;
	}