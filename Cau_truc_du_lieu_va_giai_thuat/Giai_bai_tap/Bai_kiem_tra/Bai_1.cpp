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
void ShowNode (NodePtr q) {
	cout << q->info <<" ";
}

void ShowList(NodePtr pList) {
    NodePtr p;
    if(pList == NULL) {
		return;
	}
    p = pList->next;
    do {
		ShowNode(p);
		p = p->next;
	} while(p != pList->next); 
}
void InsertLast(NodePtr &pList, int x) {
    NodePtr node;
    node = new NODE;
    node->info = x;
    if(pList == NULL) {
		pList = node;
		pList->next = pList;
    } else {
		node->next = pList->next;
		pList->next = node;
		pList = node;
    }
}
void InsertBefore(NodePtr &pList, NodePtr &p, int x) {
	if(p == NULL) {
		return;
	}
	else {	
		NodePtr q,node;
		node = new NODE;
		q = pList->next;
		while(q->next != p) {
			q= q->next;
		}
		node->info = x;
		q->next = node;
		node->next = p;
	}
}

void Delete_x(NodePtr &pList, int x) {
	NodePtr p;
	p = pList->next;
	do{
		p=p->next;
	} while(p != pList->next && p->info != x);
	if(p == pList->next) {
		cout <<"Nut "<<x<<" khong co trong danh sach."<<endl;
		return;
	}
	else {
		NodePtr q = pList->next;
		while(q->next != p) {
			q = q->next;
		}
		q -> next = p -> next;
		delete p;
	}
}

int main() {
	NodePtr pList;
	Init(pList);
	int n, c;
	cout << "Nhap so luong node trong danh sach la: ";
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cout << "Nhap gia tri node thu " << i << " la: ";
		cin >> c;
		InsertLast(pList, c);
	}
	cout << "Hien thi danh sach la: ";
	ShowList(pList);
	int h, k;
	cout << "\nNhap gia tri bo sung vao node truoc nut p la: ";
	cin >> h;
	cout << "Nhap vi tri bo sung vao truoc nut p la: ";
	cin >> k;
	NodePtr p = pList->next;
	for(int i = 1; i < k; i++) {
		p = p->next;
	}
	InsertBefore(pList, p, h);
	cout << "Hien thi danh sach sau khi bo sung la: ";
	ShowList(pList);
	int x;
	cout << "\nNhap gia tri x can xoa trong danh sach la: ";
	cin >> x;
	Delete_x(pList, x);
	cout << "Hien thi danh sach sau khi xoa la: ";
	ShowList(pList);
	return 0;
}