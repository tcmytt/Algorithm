#include<iostream>
using namespace std;
typedef struct node {
    int info;
    struct node* next;
} NODE;

typedef NODE* NodePtr;
NodePtr pHead = NULL;

void Init(NodePtr &pHead) {
    pHead = NULL;
}
void InsertLast(NodePtr &pHead, int x) {
		NodePtr node;
		node = new NODE;
		node->info = x;
		node->next = NULL;
		if(pHead == NULL) {
			pHead = node;
		} else {
   			NODE *p;
			p = pHead;
			while(p->next != NULL) {
				p = p->next;	
			}
			p->next = node;
		}
}

void nhap(NodePtr &pHead) {
 	int  n;
 	cout<<"Nhap so node cua danh sach: "; cin>>n;
 	for(int i=1;i<=n;i++)
 	{	int x;			
 		cout<<"Nhap node thu "<<i<<":";
 		cin>>x;
 		InsertLast(pHead,x);
	 }
}
void ShowNode(NodePtr	q)
{	
	cout<<q->info<<"\t";
}
void ShowList(NodePtr pHead) {
    NodePtr p;
    p = pHead;
    while(p != NULL) {
    	ShowNode(p);
    	p = p->next;
    }
}
void DeleteBefore(NodePtr &pHead, NodePtr &p)
{
	if(p == NULL)
	{
		cout<<"cannot delete node! ";
	}
	else
	{
		NodePtr q, r;
		r = pHead; 
		q = pHead->next;
		while(q->next != p)
		{
			q = q->next;
			r = r->next;
		}
		r->next = p;
		delete p;
	}
}
void Mod_7(NodePtr pHead)
{	NodePtr	p = pHead;
	while (p != NULL)
	{	if (p->info%7==0)
			ShowNode(p);
		p = p -> next;
	}
}
int main()
{	int x, y;
	Init(pHead);
	nhap(pHead);	
	cout<<"Danh sach da nhap la: "<<endl;
	ShowList(pHead);
	cout<<"\nNhap gia tri nut can bo sung: ";cin>>x;
	cout<<"\n Bo sung 1 node moi thong tin x vao lam cuoi danh sach: ";
	cout<<"\n Danh sach sau khi bo sung la: "<<endl;
	InsertLast(pHead,x);
	ShowList(pHead);
	NodePtr p = pHead;
    int k;
    cout<<"\n Nhap phan tu vi tri node p:";
    cin>>k;
    for(int i = 0;i< k; i++)
    {
       	p= p->next;
	}
    DeleteBefore(pHead,p);
    cout<<"\n Xoa node truoc node thu "<<k<<"(node p) :" <<endl;
    ShowList(pHead);
	cout<<"\n Cac nut chia het cho 7 trong danh sach la: "<<endl;
	Mod_7(pHead);
	cout<<endl;
	return 0;
}