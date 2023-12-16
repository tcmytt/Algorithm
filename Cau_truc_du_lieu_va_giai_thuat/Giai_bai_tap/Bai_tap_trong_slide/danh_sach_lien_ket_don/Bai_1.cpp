#include<iostream>
using namespace std;

typedef struct node {
    int info;
    node* next;
} NODE;

typedef NODE* NodePtr;
NodePtr pHead;

void Init(NodePtr &pHead) {
    pHead = NULL;
}

int IsEmpty(NodePtr pHead) {
    return (pHead == NULL);
}

void InsertLast(NodePtr &pHead, int x) {
    NodePtr node = new NODE;
    node->info = x;
    node->next = NULL;
    if(pHead == NULL) {
        pHead = node;
    }
    else {
        NodePtr p = pHead;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = node;
    }
}

int count(NodePtr pHead) {
    int count = 0;
    NodePtr p = pHead;
    while(p != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

void InsertFirst(NodePtr &pHead, int x) {
    NodePtr node;
    node = new NODE;
    node->info = x;
    node->next = NULL;
    node->next = pHead;
    pHead = node;
}

void InsertNode(NodePtr &pHead, int k, int x) {
    NodePtr node;
    node = new NODE;
    node->info = x;
    int d = 1;
    NodePtr p, q;
    p = pHead->next;
    q = pHead;
    while(d != k-1) {
        d++;
        p = p->next;
        q = q->next;
    }
    q->next = node;
    node->next = p;
}

void DeleteNode(NodePtr pHead, int y) {
    NodePtr p;
    p = pHead;
    while(p != NULL && p->info != y) {
        p = p->next;
    }
    if(p == NULL) {
        cout << "Nut " << y << " khong co trong danh sach." << endl;
    }
    else {
        NodePtr q = pHead;
        while(q->next != p) {
            q = q->next;
        }
        q->next = p->next;
        delete p;
    }
}

void Mod_5(NodePtr pHead) {
    NodePtr p = pHead;
    while(p != NULL) {
        if(p->info % 5 == 2) {
            cout << p->info << " ";
        }
        p = p->next;
    }
}

void ShowNode(NodePtr pHead) {
    NodePtr p = pHead;
    while(p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}

int main() {
    NodePtr pHead;
    Init(pHead);
    int n, x;
    cout << "Nhap so node can nhap vao la: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Nhap node thu " << i + 1 << " la: ";
        cin >> x;
        InsertLast(pHead, x);
    }
    cout << "Hien thi danh sach lien ket la: ";
    ShowNode(pHead);
    cout << "\nSo nut co trong danh sach la: " << count(pHead);
    int k;
    cout << "\nNhap gia tri nut can bo sung la: ";
    cin >> x;
    cout << "Nhap vi tri nut can bo sung la: ";
    cin >> k;
    if(k == 1) {
        InsertFirst(pHead, x);
    }
    else {
        InsertNode(pHead, k, x);
    }
    cout << "Hien thi danh sach sau khi bo sung la: ";
    ShowNode(pHead);
    int y;
    cout << "\nNhap gia tri nut can xoa: ";
    cin >> y;
	DeleteNode(pHead,y);
    cout << "So nut co trong danh sach la: " << count(pHead);
	cout << "\nDanh sach sau khi xoa nut la: ";
	ShowNode(pHead);
    cout << "\nCac nut chia 5 du 2 trong danh sach la: "<<endl;
	Mod_5(pHead);
    return 0;
}