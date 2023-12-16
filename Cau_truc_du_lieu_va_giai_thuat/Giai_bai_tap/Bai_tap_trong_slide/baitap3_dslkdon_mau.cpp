#include"iostream"
using namespace std;

typedef struct node
{
	int info;
	node* next;
}NODE;
typedef NODE* NodePtr;
NodePtr pHead;

void khoitao(NodePtr &pHead)
{
	pHead = NULL;
}

int IsEmpy(NodePtr pHead)
{
	return (pHead == NULL);
}

void ShowNode(NodePtr q)
{
	cout<< q->info <<" ";
}

void ShowList(NodePtr pHead)
{
	NodePtr p;
	p = pHead;
	while(p != NULL)
	{
		ShowNode(p);
		p = p->next;
	}
}

void InsertLast(NodePtr &pHead, int x)
{
	NodePtr node;
	node = new NODE;
	node->info = x;
	node->next = NULL;
	
	if(pHead == NULL) 
		pHead = node;
	else
	{
		NodePtr p;
		p = pHead;
		while(p->next !=  NULL)
			p = p->next;
		p->next = node;
	}
}


void Nhapds(NodePtr &pHead)
{
	int n;
	cout<<"\nNhap so phan tu cua danh sach: "; cin>>n;
	for(int i = 0; i<n; i++)
	{
		int x;
		cout<<"\nGia tri cua nut thu "<<i+1<<"\t";
		cin>>x;
		InsertLast(pHead,x);
	}
}

// them cao truoc ut bat ky
void Them_Truoc_Bat_Ky(NodePtr &pHead,NodePtr &p, int x)
{
	NodePtr node;
	node = new NODE;
	node->info= x;
	
	if(p == NULL)
		cout<<"\nKhong chem dc.";
	else
	{
		NodePtr q;
		q = pHead;
		while(q->next != p)
		{
			q = q->next;
		}
		node->next = q->next;
		q->next = node;
	}
}

void Delete_Last(NodePtr &pHead)
{
	if(pHead == NULL)
	{
		cout<<"\nKhong the xoa.";
	}
	else
	{
		NodePtr q,p;
		p = pHead->next;
		q = pHead;
		while(p->next != NULL)
		{
			p = p->next;
			q = q->next;
		}
		delete p;
		q->next = NULL;
	}
}
NodePtr Timkiem(NodePtr pHead, int x)
 {
 	NodePtr p; 
 	p = pHead; 
 	while ( p != NULL && p->info != x) 
 	p = p->next;
 	return p;
 }




main()
{
	int x,y;
	khoitao(pHead);
	Nhapds(pHead);
	cout<<"\nDanh sach vua nhap la: ";
	ShowList(pHead);
	cout<<"\nGia tri cua noi duoc them la: "; cin>>x;
	cout<<"\n Vi tri can them vao truoc: "; cin>>y;
	NodePtr p = pHead;
	for(int i = 0; i< y; i++)
	{
		p=p->next;
	}
	Them_Truoc_Bat_Ky(pHead,p,x);
	cout<<"\nDanh sach sau khi duoc them la: ";
	ShowList(pHead);
	
	Delete_Last(pHead);
	cout<<"\nDanh sach sau khi xoa cuoi la: ";
	ShowList(pHead);
	
	cout<<"\nNhap phan tu can tim: ";cin>>x;
	if(Timkiem(pHead,x)==NULL)
		cout<<"Phan tu "<<x<<" khong co trong danh sach"<<endl;
	else
	{	
		cout<<"Phan tu "<<x<<" co trong danh sach";
		cout<<" o vi tri "<<Timkiem(pHead,x)<<endl;
	}
	
	
	cout<<endl;
	system("pause");
	return 0;
}