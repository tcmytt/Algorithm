#include <iostream>
#include <string>
#include <iomanip>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

using namespace std;

struct SinhVien
{
    int ma;
    string ten;
    string lop;
    float toan, ly, hoa;
};

const int MAL = 4;
const int TENL = 30;
const int LOPL = 10;
const int DIEML = 6;

void show(SinhVien sv)
{
    cout << left;
    cout << setw(MAL) << sv.ma;
    cout << setw(TENL) << sv.ten;
    cout << setw(LOPL) << sv.lop;
    cout << right;
    cout << setw(DIEML) << sv.toan;
    cout << setw(DIEML) << sv.ly;
    cout << setw(DIEML) << sv.hoa;
    cout << endl;
}

void header()
{
    cout << left;
    cout << setw(MAL) << "Ma";
    cout << setw(TENL) << "Ho ten";
    cout << setw(LOPL) << "Lop";
    cout << right;
    cout << setw(DIEML) << "Toan";
    cout << setw(DIEML) << "Ly";
    cout << setw(DIEML) << "Hoa";
    cout << endl;
}

void catchInvalid(string field, float &score)
{
    while (score < 0 || score > 10)
    {
        cout << "Khong hop le. Nhap lai." << endl;
        cout << "\tNhap diem " << field << ": ";
        cin >> score;
    }
}

SinhVien insert(int ma)
{
    SinhVien sv;
    sv.ma = ma;
    cout << "\tNhap ho ten: ";
    cin.ignore();
    fflush(stdin);
    getline(cin, sv.ten);
    cout << "\tNhap ten lop: ";
    fflush(stdin);
    getline(cin, sv.lop);
    cout << "\tNhap diem Toan: ";
    cin >> sv.toan;
    catchInvalid("Toan", sv.toan);
    cout << "\tNhap diem Ly: ";
    cin >> sv.ly;
    catchInvalid("Ly", sv.ly);
    cout << "\tNhap diem Hoa: ";
    cin >> sv.hoa;
    catchInvalid("Hoa", sv.hoa);
    return sv;
}

struct Node
{
    SinhVien info;
    struct Node *prev;
    struct Node *next;
};

typedef Node *NodePtr;

struct List
{
    NodePtr pHead;
    NodePtr pTail;
};

void Init(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NodePtr CreateNode(SinhVien sv)
{
    NodePtr node = new Node;
    node->info = sv;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int IsEmpty(List l)
{
    return (l.pHead == NULL && l.pTail == NULL);
}

void ShowNode(NodePtr q)
{
    show(q->info);
}

void ShowList(List l)
{
    if (IsEmpty(l))
        return;
    NodePtr p = l.pHead;
    while (p != NULL)
    {
        ShowNode(p);
        p = p->next;
    }
}

void ShowReverse(List l)
{
    if (IsEmpty(l))
        return;
    NodePtr p = l.pTail;
    while (p != NULL)
    {
        ShowNode(p);
        p = p->prev;
    }
}

void InsertFirst(List &l, SinhVien sv)
{
    NodePtr node = CreateNode(sv);
    if (IsEmpty(l))
    {
        l.pHead = l.pTail = node;
    }
    else
    {
        node->next = l.pHead;
        l.pHead->prev = node;
        l.pHead = node;
    }
}

void InsertLast(List &l, SinhVien sv)
{
    NodePtr node = CreateNode(sv);
    if (IsEmpty(l))
    {
        l.pHead = l.pTail = node;
    }
    else
    {
        l.pTail->next = node;
        node->prev = l.pTail;
        l.pTail = node;
    }
}

void InsertBefore(List &l, NodePtr &p, SinhVien sv)
{
    if (p == NULL)
        return;
    if (p == l.pHead)
        InsertFirst(l, sv);
    else
    {
        NodePtr node = CreateNode(sv);
        NodePtr before = p->prev;
        before->next = node;
        node->prev = before;
        node->next = p;
        p->prev = node;
    }
}

void InsertAfter(List &l, NodePtr &p, SinhVien sv)
{
    if (p == NULL)
        return;
    if (p == l.pHead)
        InsertLast(l, sv);
    else
    {
        NodePtr node = CreateNode(sv);
        NodePtr after = p->next;
        after->prev = node;
        node->next = after;
        node->prev = p;
        p->next = node;
    }
}

void DeleteFirst(List &l)
{
    if (IsEmpty(l))
        return;
    else if (l.pHead->prev == l.pHead->next)
    {
        delete l.pHead;
        l.pHead = NULL;
    }
    else
    {
        NodePtr p = l.pHead;
        l.pHead = l.pHead->next;
        l.pHead->prev = NULL;
        delete p;
    }
}

void DeleteLast(List &l)
{
    if (IsEmpty(l))
        return;
    else if (l.pTail->prev == l.pTail->next)
    {
        delete l.pTail;
        l.pTail = NULL;
    }
    else
    {
        NodePtr p = l.pTail;
        l.pTail = l.pTail->prev;
        l.pTail->next = NULL;
        delete p;
    }
}

void DeleteNode(List &l, NodePtr &p)
{
    if (p == NULL)
        return;
    if (p == l.pHead)
        DeleteFirst(l);
    if (p == l.pTail)
        DeleteLast(l);
    else
    {
        NodePtr left = p->prev;
        NodePtr right = p->next;
        left->next = right;
        if (right != NULL)
            right->prev = left;
        delete p;
    }
}

NodePtr Search(List l, int ma)
{
    if (IsEmpty(l))
        return NULL;
    NodePtr p = l.pHead;
    while (p->info.ma != ma && p->next != NULL)
        p = p->next;
    if (p->info.ma == ma)
        return p;
    else
        return NULL;
}

NodePtr SearchByClass(NodePtr pHead, string lop)
{
    if (pHead == NULL)
        return NULL;
    NodePtr p = pHead;
    while (p->info.lop.compare(lop) != 0 && p->next != NULL)
        p = p->next;
    if (p->info.lop.compare(lop) == 0)
        return p;
    else
        return NULL;
}

NodePtr SearchByMathScoreMoreThan(NodePtr pHead, int toan)
{
    if (pHead == NULL)
        return NULL;
    NodePtr p = pHead;
    while (p->info.toan != toan && p->next != NULL)
        p = p->next;
    if (p->info.toan >= toan)
        return p;
    else
        return NULL;
}

NodePtr SearchByName(NodePtr pHead, string ten)
{
    if (pHead == NULL)
        return NULL;
    NodePtr p = pHead;
    while (p->info.ten.find(ten) == string::npos && p->next != NULL)
        p = p->next;
    if (p->info.ten.find(ten) != string::npos)
        return p;
    else
        return NULL;
}

void ClearList(List &l)
{
    while (l.pHead != NULL)
    {
        DeleteFirst(l);
    }
}

int CompareNodes(NodePtr q, NodePtr p, string s, string exp)
{
    if (s.compare("ma") == 0)
    {
        if (exp.compare(">=") == 0)
        {
            if (q->info.ma >= p->info.ma)
                return 1;
        }
        else if (exp.compare("<") == 0)
        {
            if (q->info.ma < p->info.ma)
                return 1;
        }
    }
    else if (s.compare("toan") == 0)
    {
        if (exp.compare(">=") == 0)
        {
            if (q->info.toan >= p->info.toan)
                return 1;
        }
        else if (exp.compare("==") == 0)
        {
            if (q->info.toan == p->info.toan)
                return 1;
        }
        else if (exp.compare(">") == 0)
        {
            if (q->info.toan > p->info.toan)
                return 1;
        }
    }
    else if (s.compare("ly") == 0)
    {
        if (exp.compare("==") == 0)
        {
            if (q->info.ly == p->info.ly)
                return 1;
        }
        else if (exp.compare(">") == 0)
        {
            if (q->info.ly > p->info.ly)
                return 1;
        }
    }
    else if (s.compare("hoa") == 0)
    {
        if (exp.compare(">") == 0)
        {
            if (q->info.hoa > p->info.hoa)
                return 1;
        }
    }
    return 0;
}

void SortedInsert(List &l, NodePtr &p, string s)
{
    if (IsEmpty(l))
        l.pHead = p;
    else if (CompareNodes(l.pHead, p, s, ">="))
    {
        p->next = l.pHead;
        p->next->prev = p;
        l.pHead = p;
    }
    else
    {
        NodePtr q = l.pHead;
        while (q->next != NULL && CompareNodes(l.pHead, p, s, "<"))
            q = q->next;
        p->next = q->next;
        if (q->next != NULL)
            p->next->prev = p;
        q->next = p;
        p->prev = q;
    }
}

void InsertionSort(List &l, string s)
{
    if (IsEmpty(l))
        return;
    List res;
    Init(res);
    NodePtr p = l.pHead;
    while (p != NULL)
    {
        NodePtr next = p->next;
        p->prev = p->next = NULL;
        SortedInsert(res, p, s);
        p = next;
    }
    l = res;
}

void BubbleSort(List &l, string s)
{
    if (IsEmpty(l))
        return;
    bool swapped;
    NodePtr ptr1;
    NodePtr lptr = NULL;
    do
    {
        swapped = false;
        ptr1 = l.pHead;
        while (ptr1->next != lptr)
        {
            if (CompareNodes(ptr1, ptr1->next, s, ">"))
            {
                swap(ptr1->info, ptr1->next->info);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void BubbleSort2(List &l, string s1, string s)
{
    if (IsEmpty(l))
        return;
    bool swapped;
    NodePtr ptr1;
    NodePtr lptr = NULL;
    do
    {
        swapped = false;
        ptr1 = l.pHead;
        while (ptr1->next != lptr)
        {
            if (CompareNodes(ptr1, ptr1->next, s1, "==") && CompareNodes(ptr1, ptr1->next, s, ">"))
            {
                swap(ptr1->info, ptr1->next->info);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void BubbleSort3(List &l, string s1, string s2, string s)
{
    if (IsEmpty(l))
        return;
    bool swapped;
    NodePtr ptr1;
    NodePtr lptr = NULL;
    do
    {
        swapped = false;
        ptr1 = l.pHead;
        while (ptr1->next != lptr)
        {
            if (CompareNodes(ptr1, ptr1->next, s1, "==") && CompareNodes(ptr1, ptr1->next, s2, "==") && CompareNodes(ptr1, ptr1->next, s, ">"))
            {
                swap(ptr1->info, ptr1->next->info);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void Ham1(List l)
{
    if (!IsEmpty(l))
    {
        cout << "Danh sach sinh vien:" << endl;
        header();
        ShowList(l);
    }
    else
    {
        cout << "Khong co du lieu hien thi." << endl;
    }
}

void Ham2(List l)
{
    int ma;
    cout << "Nhap ma sinh vien ban can tim: ";
    cin >> ma;
    NodePtr p = Search(l, ma);
    if (p != NULL)
    {
        cout << "Thong tin sinh vien voi ma " << ma << ":" << endl;
        header();
        ShowNode(p);
    }
    else
    {
        cout << "Khong co sinh vien nao voi ma " << ma << "." << endl;
    }
}

void Ham3(List &l)
{
    bool check;
    int ma;
    cout << "Nhap thong tin sinh vien moi:" << endl;
    do
    {
        check = false;
        cout << "\tNhap ma: ";
        cin >> ma;
        NodePtr p = Search(l, ma);
        if (p != NULL)
        {
            cout << "Ma " << ma << " da ton tai!" << endl;
            check = true;
        }
    } while (check);
    SinhVien sv = insert(ma);
    InsertLast(l, sv);
    cout << "Them sinh vien thanh cong." << endl;
}

void Ham4(List &l)
{
    int ma;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> ma;
    NodePtr p = Search(l, ma);
    if (p != NULL)
    {
        DeleteNode(l, p);
        cout << "Xoa sinh vien thanh cong." << endl;
    }
    else
    {
        cout << "Khong co sinh vien nao voi ma " << ma << "." << endl;
    }
}

void Ham5(List l)
{
    string lop;
    cout << "Nhap ten lop can tim: ";
    cin.ignore();
    fflush(stdin);
    getline(cin, lop);
    NodePtr p = SearchByClass(l.pHead, lop);
    if (p != NULL)
    {
        cout << "Danh sach sinh vien lop " << lop << ":" << endl;
        header();
        while (p != NULL)
        {
            ShowNode(p);
            p = SearchByClass(p->next, lop);
        }
    }
    else
    {
        cout << "Khong co sinh vien nao thuoc lop " << lop << "." << endl;
    }
}

void Ham6(List l)
{
    int toan = 5, count = 0;
    cout << "Tong so sinh vien co diem Toan >= " << toan << ": ";
    NodePtr p = SearchByMathScoreMoreThan(l.pHead, toan);
    while (p != NULL)
    {
        count++;
        p = SearchByMathScoreMoreThan(p->next, toan);
    }
    cout << count << endl;
}

void Ham7(List l)
{
    string ten;
    cout << "Nhap ten sinh vien can tim: ";
    cin.ignore();
    fflush(stdin);
    getline(cin, ten);
    NodePtr p = SearchByName(l.pHead, ten);
    if (p != NULL)
    {
        cout << "Danh sach sinh vien co ten " << ten << ":" << endl;
        header();
        while (p != NULL)
        {
            ShowNode(p);
            p = SearchByName(p->next, ten);
        }
    }
    else
    {
        cout << "Khong co sinh vien nao co ten " << ten << "." << endl;
    }
}

void Ham8(List &l)
{
    if (IsEmpty(l))
    {
        cout << "Khong co sinh vien nao de sap xep." << endl;
    }
    else
    {
        InsertionSort(l, "ma");
        cout << "Sap xep sinh vien thanh cong." << endl;
    }
}

void Ham9(List &l)
{
    if (IsEmpty(l))
    {
        cout << "Khong co sinh vien nao de sap xep." << endl;
    }
    else
    {
        BubbleSort(l, "toan");
        BubbleSort2(l, "toan", "ly");
        BubbleSort3(l, "toan", "ly", "hoa");
        cout << "Sap xep sinh vien thanh cong." << endl;
    }
}

void Ham10(List &l)
{
    string lop;
    cout << "Nhap ten lop can huy sinh vien: ";
    cin.ignore();
    fflush(stdin);
    getline(cin, lop);
    NodePtr p = SearchByClass(l.pHead, lop);
    if (p != NULL)
    {
        while (p != NULL)
        {
            NodePtr next = p->next;
            DeleteNode(l, p);
            p = SearchByClass(next, lop);
        }
        cout << "Xoa sinh vien thanh cong." << endl;
    }
    else
    {
        cout << "Khong co sinh vien nao thuoc lop " << lop << "." << endl;
    }
}

void pause()
{
    string s;
    cout << "Nhan Enter de tiep tuc." << endl;
    cin.ignore();
    fflush(stdin);
    getline(cin, s);
}

void input(List &l)
{
    int n;
    do
    {
        cout << "Nhap so sinh vien: ";
        cin >> n;
        if (n < 0)
            cout << "Khong hop le. Nhap lai." << endl;
    } while (n < 0);
    for (int i = 0; i < n; i++)
    {
        Ham3(l);
    }
}

void menu(List l)
{
    bool check = true;
    do
    {
        if (system("CLS"))
            system("clear");
        cout << "---------------------------MENU---------------------------" << endl;
        cout << "| 1. Hien thi toan bo danh sach                          |" << endl;
        cout << "| 2. Tim 1 SV theo ma SV                                 |" << endl;
        cout << "| 3. Them 1 SV vao cuoi danh sach                        |" << endl;
        cout << "| 4. Xoa 1 SV khoi danh sach tu ma SV                    |" << endl;
        cout << "| 5. Hien thi danh sach SV thuoc ve 1 lop nhap vao       |" << endl;
        cout << "| 6. Tinh tong so SV co diem toan >= 5                   |" << endl;
        cout << "| 7. Hien thi toan bo danh sach SV chua ten nhap vao     |" << endl;
        cout << "| 8. Sap xep danh sach tang dan theo ma SV               |" << endl;
        cout << "| 9. Sap xep danh sach tang dan theo diem Toan, roi den  |" << endl;
        cout << "| diem Ly, roi den diem Hoa                              |" << endl;
        cout << "| 10. Huy toan bo cac SV thuoc ve lop nhap vao           |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << endl;
        int choice;
        cout << "Moi ban nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Ham1(l);
            break;
        case 2:
            Ham2(l);
            break;
        case 3:
            Ham3(l);
            break;
        case 4:
            Ham4(l);
            break;
        case 5:
            Ham5(l);
            break;
        case 6:
            Ham6(l);
            break;
        case 7:
            Ham7(l);
            break;
        case 8:
            Ham8(l);
            break;
        case 9:
            Ham9(l);
            break;
        case 10:
            Ham10(l);
            break;
        default:
            check = false;
            break;
        }
        if (check)
            pause();
    } while (check);
}

int main()
{
    List l;
    Init(l);
    input(l);
    menu(l);
    return 0;
}
