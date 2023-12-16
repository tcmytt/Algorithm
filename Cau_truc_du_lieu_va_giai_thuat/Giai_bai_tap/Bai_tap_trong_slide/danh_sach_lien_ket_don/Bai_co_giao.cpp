#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct SinhVien{
	char tensv[25];
	char masv[12];
	int gioitinh;
	float diem;
};

struct NODE {
	SinhVien info;
	NODE* next;
};

typedef NODE* NodePtr;

NodePtr pHead = NULL;

void Init(NodePtr &pHead) {
	pHead = NULL;
}

int InEmpty(NodePtr pHead)
{
	if(pHead == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Nhap (SinhVien &SV)
{
	fflush(stdin);
	cout << "Nhap ma sinh vien: ";
	cin.getline(SV.masv, 25);
	cout << "Nhap ten sinh vien: ";
	cin.getline(SV.tensv, 12);
	cout << "Nhap gioi tinh(nam nhap: 1; nu nhap: 2): ";
	cin >> SV.gioitinh;
	cout << "Nhap diem: ";
	cin >> SV.diem;
}

void HienThi() {
	cout << setw(30) << left << "Ma mon" << setw(30) << left << "Ten sinh vien";
	cout << setw(30) << left << "Khoa" << setw(30) << left << "So tin chi";
	cout << setw(30) << left << "Giang vien" << endl;
}
void ShowNode (NodePtr q) {
	cout << setw(30) << left << q->info.masv;
	cout << setw(30) << left << q->info.tensv;
	cout << setw(30) << left << q->info.gioitinh;
	cout << setw(30) << left << q->info.diem << endl;
}
void ShowList(NodePtr pHead) {
	NodePtr p;
	p = pHead;
	while (p != NULL)
	{
		ShowNode(p);
		p = p->next;
	}
}
void InsertLast(NodePtr &pHead, SinhVien &SV) {
		NodePtr node;
		node = new NODE;
		node->info = SV;
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
void Search(NodePtr pHead, SinhVien SV)
{
	char masv[25];
	fflush(stdin);
	cout<<"\nNhap ten sinh vien can tim: ";
	cin.getline(SV.masv, 25);
	NodePtr p;
	p = pHead;
	HienThi();
	while(p != NULL ) {
		if(p->info.masv == masv)
		ShowNode(p);
		p = p->next;
	}
}
void DeleteFirst(NodePtr &pHead) {
	NodePtr p;
	if(InEmpty(pHead) == 1) {
		cout <<"Danh sach trong.";
	} else {
		p = pHead;
		pHead = pHead->next;
		delete p;
	}
}

void DeleteLast(NodePtr &pHead) {
	if(pHead == NULL) {
		cout <<"Danh sach trong.";
	} else {
		NodePtr p, q;
		p = pHead->next;
		q = pHead;
		while(p->next != NULL) {
			p = p->next;
			q = q->next;
		}
		delete p;
		q->next = NULL;
	}
}
void XoaSinhVien(NodePtr &pHead, SinhVien &SV)
{
	NodePtr p;
	char masv[25];
	cout<<"\nNhap ma sinh vien can xoa: ";
	cin.getline(SV.masv, 25);
	NodePtr q ;
	q = pHead;
	while(q != NULL) {
		q = q->next;
		if(p->info.masv == masv)
		{
			if(p == pHead)
				DeleteFirst(pHead);
			else if(p == q)
				DeleteLast(pHead);
			else
			{
				NodePtr c = pHead;
				while(c->next != p)
				{
					c = c->next;
				}
				c->next = p->next;
				delete p;
			}
		}
	}
	if(p == NULL)
    	cout<<"\n => Khong tim thay sinh vien co ma so nay: " << masv << endl;
    else
    	cout<<"\n => Xoa thanh cong. "<<endl;
}

void TongDiem(NodePtr &pHead)
{
	float tong = 0;
	for(NodePtr p = pHead; p != NULL; p= p->next)
	{
		if(p->info.diem >= 3)
		{
			tong++;
		}
	}
	cout<<"\n => Tong so sinh vien co so tin chi >= 3 la: "<<tong<<" ( mon )"<<endl;
}
void Ketoan(NodePtr &pHead, SinhVien SV)
{
	char tensv[12];
	cout<<"\n [*] Nhap ten sinh vien can hien thi trong danh sach: ";
	cin.getline(SV.tensv, 25);
	HienThi();
	for(NodePtr p = pHead; p != NULL; p= p ->next)
	{
		if(p->info.tensv == tensv)
		{
			ShowNode(p);	
		}
	}
}
void CoKhi(NodePtr &pHead)
{
	cout<<"\n\n [+] Hien thi danh danh sach khoa co khi : "<<endl;
	HienThi();
	for(NodePtr p = pHead; p != NULL; p = p->next)
	{
		if(p->info.khoa == "Co khi"|| p->info.khoa =="CO KHI"||p->info.khoa =="Co Khi")
		{
			ShowNode(p);
		}
	}
	
}
void SXTin(NodePtr &pHead)
{
	cout<<"\n---------DANH SACH SAP XEP TANG THEO SO TIN------"<<endl;
	for (NodePtr q = pHead; q != NULL; q = q->next) 
	for (NodePtr p = q->next; p != NULL; p = p->next) 
	if(q->info.stc > p->info.stc)
	swap(q->info,p->info);
}
void SXDiem(NodePtr &pHead)
{
	cout<<"\n---------DANH SACH SAP XEP TANG THEO DIEM------"<<endl;
	for (NodePtr q = pHead; q != NULL; q = q->next) 
	for (NodePtr p = q->next; p != NULL; p = p->next) 
	if(q->info.stc > p->info.stc)
	swap(q->info,p->info);
}
void Xoakhoa(NodePtr &pHead)
{
	NodePtr p;
	string khoa;
	cout<<"\n Nhap ma sinh vien can xoa: ";
	getline(cin,khoa);
	NodePtr q ;
	q = pHead;
	while(q != NULL)
	{
		q = q->next;
	}
for(NodePtr h = pHead; h != NULL; h=h->next)
{
	for(p = pHead; p != NULL; p=p->next)
	{
		if(p->info.khoa == khoa)
		{
			if(p == pHead)
				DeleteFirst(pHead);
			else if(p == q)
				DeleteLast(pHead);
			else
			{
				NodePtr c = pHead;
				while(c->next != p)
				{
					c = c->next;
				}
				c->next = p->next;
				delete p;
			}
		}
	}
}
	if(p == NULL)
    cout<<"\n =>>>>> Khong tim thay khoa can xoa !! "<<endl;
    else
    cout<<"\n =>> Xoa thanh cong kkkkk. "<<endl;
}
int main()
{			 
		cout<<"\n-----------------------------MENU-----------------------------"<<endl;
		cout<<  "| 1. Hien thi toan bo danh sach			                 |"<<endl;
		cout<<  "| 2. Tim mot sinh vien theo ten			                 |"<<endl;
		cout<<  "| 3. Them mot sinh vien vao cuoi danh sach			 |"<<endl;
		cout<<  "| 4. Xoa mot sinh vien khoi danh sach			         |"<<endl;
		cout<<  "| 5. Tinh tong so sinh vien co so tin chi >= 3			 |"<<endl;
		cout<<  "| 6. Hien thi toan bo danh sach sinh vien chua ten nhap vao	 |"<<endl;
		cout<<  "| 7. Hien thi danh sach sinh vien cua khoa Co khi			 |"<<endl;
		cout<<  "| 8. Sap xep danh sach tang dan theo so tin chi			 |"<<endl;
		cout<<  "| 9. Sap xep danh sach	tang dan theo diem		         |"<<endl;
		cout<<  "| 10. Huy toan bo mot khoa			                 |"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"\n\t\t => XIN MOI BAN  CHON : ";
	cout<<"\n  [+++] Nhap lua chon :";
	int lc;
	do{
		cin>>lc;
		if(lc < 0 || lc> 10)
		cout<<"Khong co lua chon nay!!!. Vui long nhap lai lua chon: ";
	}while(lc < 0 || lc> 10);
	NodePtr pHead;
	Init(pHead);
	int n;
	cout<<"\n [+] Nhap so luong thong tin sinh vien : ";
	cin>>n;
	SinhVien *SV = new SinhVien[n];
	for(int i = 0; i< n;i++)
	{
		cout<<"[+] Nhap thong sinh vien thu "<<i+1<<": "<<endl;
		Nhap(SV[i]);
		InsertLast(pHead,SV[i]);
	}
	switch (lc)
    {
        case 1:
        {
        	HienThi();
			ShowList(pHead);	
            break;
        }
        case 2:
        {
         	Search(pHead);
            break;
        }
        case 3:
        {
        	SinhVien ch;
        	NodePtr p;
	cout<<"Nhap sinh vien vao cuoi danh sach: "<<endl;
        do{
        	p = pHead;
		cout<<" Nhap ma sinh vien: "; getline(cin,ch.ma);
        	while(p!= NULL && p->info.ma != ch.ma)
        	{
    			p= p->next;
			}
			if(p != NULL)
			cout<<"Vui long nhap lai ma: "<<endl;
  	  }while(p != NULL);
  	 	fflush(stdin);
  	  	cout<<" Nhap ten sinh vien: "; getline(cin,ch.mon);
		cout<<" Nhap khoa: "; getline(cin,ch.khoa);
		cout<<" Nhap so tin chi: ";cin>>ch.stc;
		fflush(stdin);
		cout<<" Nhap giang vien: "; getline(cin,ch.gv);
		InsertLast(pHead,ch);
			HienThi();
        	ShowList(pHead);
            break;
        }
        case 4:
        {
        	HienThi();
        	XoaMon(pHead);
        	ShowList(pHead);
            break;
        }
        case 5:
        {
        	Tongmon(pHead);
            break;
        }
        case 6:
        {
            Ketoan(pHead);
            break;
        }
        case 7:
        {
        	CoKhi(pHead);
            break;
        }
        case 8:
        {
        	HienThi();
        	SXTin(pHead);
        	ShowList(pHead);
            break;
        }
        case 9:
        {
          	
            break;
        }
        case 10:
        {
           	Xoakhoa(pHead);
           	HienThi();
           	ShowList(pHead);
            break;
        }
    }
	return 0;
}