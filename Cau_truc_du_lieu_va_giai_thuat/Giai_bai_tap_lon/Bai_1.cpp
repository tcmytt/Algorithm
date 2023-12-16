#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <windows.h>
using namespace std;

//-----------------------------------------------TAO MENU DONG----------------------------------------------
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void box(int x, int y, int w, int h, int t_color, string content)
{
    SetColor(t_color);
    for (int ix = x + 1; ix < x + w; ix++)
    {
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y + h);
        cout << char(196);
    }
    for (int iy = y + 1; iy < y + h; iy++)
    {
        gotoxy(x, iy);
        cout << char(179);
        gotoxy(x + w, iy);
        cout << char(179);
    }
    gotoxy(x, y + h);
    cout << char(195);
    gotoxy(x + w, y + h);
    cout << char(180);
    gotoxy(x + 1, y + 1);
    cout << content;
}

void Menu_dong()
{
    int x = 50, y = 3, w = 85, h = 2, color = 11;
    SetColor(11);
    gotoxy(x, y);
    cout << char(218);
    gotoxy(x + w, y);
    cout << char(191);
    gotoxy(92, 2);
    cout << "MENU" << endl;
    box(x, y, w, h, color, "0. Dung chuong trinh.");
    box(x, y += 2, w, h, color, "1. Hien thi toan bo danh sach.");
    box(x, y += 2, w, h, color, "2. Tim sinh vien theo ma sinh vien.");
    box(x, y += 2, w, h, color, "3. Them sinh vien vao cuoi danh sach.");
    box(x, y += 2, w, h, color, "4. Xoa sinh vien khoi danh sach theo ma sinh vien(nhap ma sinh vien).");
    box(x, y += 2, w, h, color, "5. Hien thi danh sach sin vien theo ten lop(nhap ten lop).");
    box(x, y += 2, w, h, color, "6. Tong so sinh vien co diem toan >= 5.");
    box(x, y += 2, w, h, color, "7. Hien thi sinh vien chua ten nhap vao.");
    box(x, y += 2, w, h, color, "8. Sap xep danh sach tang dan theo ma sinh vien.");
    box(x, y += 2, w, h, color, "9. Sap xep danh sach tang dan theo diem toan, roi den diem ly, roi den diem hoa.");
    box(x, y += 2, w, h, color, "10. Xoa sinh vien theo ten lop(nhap ten lop).");
    gotoxy(x + w, y + h);
    cout << char(217);
    gotoxy(x, y + h);
    cout << char(192);
}
// ---------------------------------------- KHOI TAO DANH SACH LIEN KET--------------------------------------------
struct SINHVIEN
{
    int masv;
    string hoten;
    string lop;
    float diemtoan;
    float diemly;
    float diemhoa;
};

typedef struct node
{
    SINHVIEN info;
    struct node *prev;
    struct node *next;
} NODE;

typedef NODE *NodePtr;

typedef struct list
{
    NodePtr pHead;
    NodePtr pTail;
} LIST;

void Init(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

bool IsEmpty(LIST L)
{
    return (L.pHead == NULL && L.pTail == NULL);
}

NodePtr Create_Node(SINHVIEN sv)
{
    NodePtr node = new NODE;
    node->info = sv;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
//---------------------------------------------------TIEU DE CHO DANH SACH--------------------------------------------
template <class T>
void khung_1_o(int x, int y, int w, int h, T content)
{
    for (int ix = x + 1; ix < x + w; ix++)
    {
        gotoxy(ix, y);
        cout << char(196);
        gotoxy(ix, y + h);
        cout << char(196);
    }
    for (int iy = y + 1; iy < y + h; iy++)
    {
        gotoxy(x, iy);
        cout << char(179);
        gotoxy(x + w, iy);
        cout << char(179);
    }
    gotoxy(x + w, y);
    cout << char(197);
    gotoxy(x + w, y + h);
    cout << char(197);
    gotoxy(x + 1, y + 1);
    cout << content;
}
void Tieu_De(int x, int y, int w, int h, int color)
{
    SetColor(color);
    gotoxy(x, y);
    cout << char(218);
    gotoxy(x, y + h);
    cout << char(195);
    khung_1_o(x, y, w, h, "MA SINH VIEN");
    khung_1_o(x += w, y, w, h, "HO VA TEN");
    gotoxy(x, y);
    cout << char(194);
    khung_1_o(x += w, y, w, h, "LOP");
    gotoxy(x, y);
    cout << char(194);
    khung_1_o(x += w, y, w, h, "DIEM TOAN");
    gotoxy(x, y);
    cout << char(194);
    khung_1_o(x += w, y, w, h, "DIEM LY");
    gotoxy(x, y);
    cout << char(194);
    khung_1_o(x += w, y, w, h, "DIEM HOA");
    gotoxy(x, y);
    cout << char(194);
    gotoxy(x + w, y + h);
    cout << char(180);
    gotoxy(x + w, y);
    cout << char(191);
}

//---------------------------------------------------HIEN THI DANH SACH-----------------------------------------------
void ShowNode(NodePtr p, int x, int y, int w, int h, int color)
{
    gotoxy(x, y);
    cout << char(195);
    gotoxy(x, y + h);
    cout << char(192);
    khung_1_o(x, y, w, h, p->info.masv);
    khung_1_o(x += w, y, w, h, p->info.hoten);
    khung_1_o(x += w, y, w, h, p->info.lop);
    khung_1_o(x += w, y, w, h, p->info.diemtoan);
    khung_1_o(x += w, y, w, h, p->info.diemly);
    khung_1_o(x += w, y, w, h, p->info.diemhoa);
    gotoxy(x + w, y);
    cout << char(180);
    gotoxy(x += w, y += h);
    cout << char(217);
}

void ShowList(LIST L, int x, int y, int w, int h, int color)
{
    NodePtr p;
    if (L.pHead == NULL)
    {
        return;
    }
    p = L.pHead;
    while (p != NULL)
    {
        ShowNode(p, x, y, w, h, color);
        y += 2;
        p = p->next;
    }
    gotoxy(x += w, y);
    cout << char(193);
    gotoxy(x += w, y);
    cout << char(193);
    gotoxy(x += w, y);
    cout << char(193);
    gotoxy(x += w, y);
    cout << char(193);
    gotoxy(x += w, y);
    cout << char(193);
    gotoxy(1, y + h + 1);
}
//-------------------------------------------------CAC THAO TAC TRONG DANH SACH LIEN KET---------------------------------
void InsertFirst(LIST &L, SINHVIEN sv)
{
    NodePtr node = Create_Node(sv);
    if (IsEmpty(L))
    {
        L.pHead = L.pTail = node;
    }
    else
    {
        node->next = L.pHead;
        L.pHead->prev = node;
        L.pHead = node;
    }
}

void InsertLast(LIST &L, SINHVIEN sv)
{
    NodePtr node = Create_Node(sv);
    if (IsEmpty(L))
    {
        L.pHead = L.pTail = node;
    }
    else
    {
        L.pTail->next = node;
        node->prev = L.pTail;
        L.pTail = node;
    }
}

void DeleteFirst(LIST &L)
{
    NodePtr p;
    if (IsEmpty(L))
    {
        return;
    }
    else if (L.pHead->prev == L.pHead->next)
    {
        delete L.pHead;
        L.pHead = NULL;
    }
    else
    {
        p = L.pHead;
        L.pHead = L.pHead->next;
        L.pHead->prev = NULL;
        delete p;
    }
}

void DeleteLast(LIST &L)
{
    if (IsEmpty(L))
    {
        return;
    }
    else if (L.pHead->prev == L.pHead->next)
    {
        delete L.pHead;
        L.pHead = NULL;
    }
    else
    {
        NodePtr p = L.pTail;
        L.pTail = L.pTail->prev;
        L.pTail->next = NULL;
        delete p;
    }
}

void DeleleNode(LIST &L, NodePtr &p)
{
    if (IsEmpty(L))
    {
        return;
    }
    if (p == L.pHead)
    {
        DeleteFirst(L);
    }
    else
    {
        NodePtr left = p->prev;
        NodePtr right = p->next;
        left->next = right;
        if (right != NULL)
        {
            right->prev = left;
        }
        delete p;
    }
}
//----------------------------------------------CAC HAM YEU CAU CUA BAI TOAN----------------------------------------------
bool Check_matrung(LIST L, int masv)
{
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.masv == masv)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void Input(SINHVIEN &sv, LIST L)
{
    do
    {
        cout << "\t+ Nhap ma sinh vien: ";
        cin >> sv.masv;
        if (Check_matrung(L, sv.masv))
        {
            cout << "->Ma sinh vien da bi trung! Yeu cau nhap lai." << endl;
        }
        if (sv.masv < 1)
        {
            cout << "->Nhap sai ma sinh vien! Yeu cau nhap lai." << endl;
        }
    } while (Check_matrung(L, sv.masv) || sv.masv < 1);
    fflush(stdin);
    cout << "\t+ Nhap ho va ten sinh vien: ";
    getline(cin, sv.hoten);
    cout << "\t+ Nhap lop sinh vien: ";
    getline(cin, sv.lop);
    do
    {
        cout << "\t+ Nhap diem toan: ";
        cin >> sv.diemtoan;
        if (sv.diemtoan < 0 || sv.diemtoan > 10)
        {
            cout << "->Nhap sai diem toan! Yeu cau nhap lai." << endl;
        }
    } while (sv.diemtoan < 0 || sv.diemtoan > 10);
    do
    {
        cout << "\t+ Nhap diem ly: ";
        cin >> sv.diemly;
        if (sv.diemly < 0 || sv.diemly > 10)
        {
            cout << "->Nhap sai diem ly! Yeu cau nhap lai." << endl;
        }
    } while (sv.diemly < 0 || sv.diemly > 10);
    do
    {
        cout << "\t+ Nhap diem hoa: ";
        cin >> sv.diemhoa;
        if (sv.diemhoa < 0 || sv.diemhoa > 10)
        {
            cout << "->Nhap sai diem hoa! Yeu cau nhap lai." << endl;
        }
    } while (sv.diemhoa < 0 || sv.diemhoa > 10);
}

void Search_Masv(LIST L, int x, int y, int w, int h, int color)
{
    int masv;
    cout << "Nhap ma sinh vien can tim la: ";
    cin >> masv;
    if (!Check_matrung(L, masv))
    {
        cout << "->Ma sinh vien vua nhap khong co!!!" << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien da tim thay theo ma sinh vien-----------------" << endl;
    Tieu_De(x, y, w, h, color);
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.masv == masv)
        {
            y += 2;
            ShowNode(p, x, y, w, h, color);
        }
        p = p->next;
    }
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(1, y + h + 1);
}

void Insert_SV(LIST L)
{
    SINHVIEN sv;
    cout << "Nhap thong tin sinh vien can them vao cuoi danh sach la: " << endl;
    Input(sv, L);
    InsertLast(L, sv);
}

void Delete_SV(LIST &L, int x, int y, int w, int h, int color)
{
    int masv;
    cout << "Nhap ma sinh vien can xoa la: ";
    cin >> masv;
    if (!Check_matrung(L, masv))
    {
        cout << "->Ma sinh vien vua nhap khong co!!! Yeu cau nhap lai." << endl;
        return;
    }
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.masv == masv)
        {
            DeleleNode(L, p);
        }
        p = p->next;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien sau khi xoa-----------------" << endl;
    Tieu_De(1, 29, 30, 2, 11);
    ShowList(L, 1, 29 + 2, 30, 2, 11);
}

bool Check_Lop(LIST L, string lop)
{
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (strcmpi(p->info.lop.c_str(), lop.c_str()) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void Search_Lop(LIST L, int x, int y, int w, int h, int color)
{
    if (IsEmpty(L))
    {
        cout << "->Danh sach trong khong the tim ten lop!!!" << endl;
        return;
    }
    string lop;
    fflush(stdin);
    cout << "Nhap ten lop can hien thi la: ";
    getline(cin, lop);
    if (!Check_Lop(L, lop))
    {
        cout << "->Lop vua nhap khong co trong danh sach!!!" << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien cua lop vua nhap-----------------" << endl;
    Tieu_De(x, y, w, h, color);
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (strcmpi((char *)p->info.lop.c_str(), (char *)lop.c_str()) == 0)
        {
            y += 2;
            ShowNode(p, x, y, w, h, color);
        }
        p = p->next;
    }
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(1, y + h + 1);
}

int Sum_Toan(LIST L)
{
    if (IsEmpty(L))
    {
        return 0;
    }
    int dem = 0;
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.diemtoan >= 5)
        {
            dem += 1;
        }
        p = p->next;
    }
    return dem;
}

bool Check_Ten(LIST L, string ten)
{
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.hoten.find(ten) != string::npos)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void Search_Ten(LIST L, int x, int y, int w, int h, int color)
{
    if (IsEmpty(L))
    {
        cout << "->Danh sach sinh vien trong!!!" << endl;
        return;
    }
    string name;
    fflush(stdin);
    cout << "Nhap ten sinh vien can tim kiem: ";
    getline(cin, name);
    if (!Check_Ten(L, name))
    {
        cout << "->Danh sach sinh vien khong co ten " << name << " !!!" << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien da tim thay-----------------" << endl;
    Tieu_De(x, y, w, h, color);
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (p->info.hoten.find(name) != string::npos)
        {
            y += 2;
            ShowNode(p, x, y, w, h, color);
        }
        p = p->next;
    }
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(x += w, y + h);
    cout << char(193);
    gotoxy(1, y + h + 1);
}

void Sort_Masv(LIST L)
{
    if (IsEmpty(L))
    {
        cout << "->Danh sach trong khong the sap xep!!!" << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien sau khi sap xep-----------------" << endl;
    for (NodePtr p = L.pHead; p != NULL; p = p->next)
        for (NodePtr q = p->next; q != NULL; q = q->next)
        {
            if (p->info.masv > q->info.masv)
            {
                swap(p->info, q->info);
            }
        }
}

void Sort_Diem(LIST L)
{
    if (IsEmpty(L))
    {
        cout << "->Danh sach trong khong the sap xe diem." << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien sau khi sap xep-----------------" << endl;
    for (NodePtr p = L.pHead; p != NULL; p = p->next)
        for (NodePtr q = p->next; q != NULL; q = q->next)
        {
            if (p->info.diemtoan > q->info.diemtoan)
            {
                swap(p->info, q->info);
            }
            if (p->info.diemly > q->info.diemly)
            {
                swap(p->info, q->info);
            }
            if (p->info.diemhoa > q->info.diemhoa)
            {
                swap(p->info, q->info);
            }
        }
}

void Delete_Lop(LIST &L, int x, int y, int w, int h, int color)
{
    if (IsEmpty(L))
    {
        cout << "->Danh sach trong khong the xoa lop." << endl;
        return;
    }
    string lop;
    fflush(stdin);
    cout << "Nhap ten lop can xoa la: ";
    getline(cin, lop);
    if (!Check_Lop(L, lop))
    {
        cout << "->Lop vua nhap khong co trong danh sach!!!" << endl;
        return;
    }
    gotoxy(51, 28);
    cout << "-----------------Danh sach sinh vien sau khi xoa-----------------" << endl;
    NodePtr p = L.pHead;
    while (p != NULL)
    {
        if (strcmpi((char *)p->info.lop.c_str(), (char *)lop.c_str()) == 0)
        {
            DeleleNode(L, p);
        }
        p = p->next;
    }
    Tieu_De(x, y, w, h, color);
    ShowList(L, x, y + 2, w, h, color);
}

int main()
{
    system("CLS");
    LIST L;
    Init(L);
    int n;
    do
    {
        cout << "Nhap so luong sinh vien can luu tru: ";
        cin >> n;
        if (n < 1)
        {
            cout << "Nhap sai! Yeu cau nhap lai." << endl;
        }
    } while (n < 1);
    SINHVIEN sv;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << " la:" << endl;
        Input(sv, L);
        InsertLast(L, sv);
    }
    int choose;
    do
    {
        system("CLS");
        Menu_dong();
        SetColor(15);
        cout << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> choose;
        if (choose < 0 || choose > 10)
        {
            cout << "Khong co lua chon nay!!! Moi ban nhap lai." << endl;
        }
        switch (choose)
        {
        case 0:
            gotoxy(51, 28);
            cout << "-----------------Da dung chuong trinh-----------------" << endl;
            break;
        case 1:
            gotoxy(51, 28);
            cout << "---------------Hien thi toan bo danh sach--------------" << endl;
            Tieu_De(1, 29, 30, 2, 11);
            ShowList(L, 1, 29 + 2, 30, 2, 11);
            break;
        case 2:
            Search_Masv(L, 1, 29, 30, 2, 11);
            break;
        case 3:
            Insert_SV(L);
            system("CLS");
            gotoxy(51, 1);
            cout << "---------------Hien thi danh sach sau khi them--------------" << endl;
            Tieu_De(1, 2, 30, 2, 11);
            ShowList(L, 1, 2 + 2, 30, 2, 11);
            break;
        case 4:
            Delete_SV(L, 1, 29, 30, 2, 11);
            break;
        case 5:
            Search_Lop(L, 1, 29, 30, 2, 11);
            break;
        case 6:
            cout << "So sinh vien co diem toan >= 5 la: " << Sum_Toan(L) << endl;
            break;
        case 7:
            Search_Ten(L, 1, 29, 30, 2, 11);
            break;
        case 8:
            Sort_Masv(L);
            Tieu_De(1, 29, 30, 2, 11);
            ShowList(L, 1, 29 + 2, 30, 2, 11);
            break;
        case 9:
            Sort_Diem(L);
            Tieu_De(1, 29, 30, 2, 11);
            ShowList(L, 1, 29 + 2, 30, 2, 11);
            break;
        case 10:
            Delete_Lop(L, 1, 29, 30, 2, 11);
            break;
        }
        system("PAUSE");
    } while (choose < 0 || choose > 10 || choose != 0);
    return 0;
}