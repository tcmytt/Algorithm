#include<iostream>
using namespace std;

typedef struct node {
    int info;
    struct node* prev;
    struct node* next;
} NODE;
typedef NODE* NodePtr;
struct Queue {
    NodePtr pFront;
    NodePtr pRear;
};

void Init(Queue &q) {
    q.pFront = NULL;
    q.pRear = NULL;
}

void Insert(Queue &q, int x) {
    NodePtr node;
    node = new NODE;
    node->info = x;
    node->next = NULL;
    if(q.pFront == NULL) {
        q.pFront = node;
        q.pRear = node;
    }
    else {
        node->prev = q.pRear;
        q.pRear->next = node;
        q.pRear = node;
    }
}

int Remove(Queue &q)
{
    if (q.pFront == NULL) {
        return -1;
    }
    NODE *p = q.pFront;
    if (q.pFront == q.pRear) {
        q.pFront = q.pRear = NULL;
    }
    else {
        q.pFront = p->next;
        q.pFront->prev = NULL;
    }
    int value = p->info;
    delete p;
    return value;
}

void ShowQueue(Queue &q) {
    NodePtr p;
    p = q.pFront;
    while(p !=NULL) {
        cout << p->info << " ";
        p=p->next;
    }
}

int main() {
    Queue q;
    Init(q);
    int n, x;
    cout << "Nhap so luong hang doi la: ";
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cout << "Nhap gia tri cua node thu " <<i + 1<<" la: ";
        cin >> x;
        Insert(q, x);
    }
    cout << "Danh sach hang doi la: ";
    ShowQueue(q);
    cout << "\nNhap gia tri can them vao hang doi la: ";
    cin >> x;
    Insert(q, x);
    cout << "Danh sach sau khi them la: ";
    ShowQueue(q);
    cout << "\nDanh sach sau khi xoa phan tu dau trong hang doi la: ";
    Remove(q);
    ShowQueue(q);
    return 0;
}