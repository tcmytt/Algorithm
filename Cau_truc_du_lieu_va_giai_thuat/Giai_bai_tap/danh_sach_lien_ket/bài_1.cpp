#include<iostream>
using namespace std;

struct Node {
    int info;
    Node *pNext;
};

struct SingleList {
    Node *pHead;
};

void init(SingleList &list) {
    Node *pHead = NULL;
}

Node *CreateNode(int d) {
    Node *pNode = new Node;
    if(pNode == NULL) {
        cout <<"Cap phat bo nho khong thanh cong.";
    } else {
        pNode->info = d;
        pNode->pNext = NULL;
    }
    return pNode;
}

void InsertLast(SingleList &list, int d) {
    Node *pNode = CreateNode(d);
    if (list.pHead == NULL) {
        list.pHead = pNode;
    } else {
        Node *pTemp = list.pHead;
        while (pTemp->pNext != NULL) {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNode;
    }
}

void output(SingleList list) {
    Node *pTemp = list.pHead;
    if(pTemp == NULL) {
        cout <<"Danh sach trong.";
    } else {
        while (pTemp != NULL) {
            cout <<pTemp->info<<" ";
            pTemp = pTemp->pNext;
        }
    }
}

int SizeOfList(SingleList list) {
    Node *pTemp = list.pHead;
    int count = 0;
    while (pTemp != NULL) {
        count++;
        pTemp = pTemp->pNext;
    }
    return count;
}

void RemoveNode(SingleList &list, int d) {
	Node *pDel= list.pHead;
        if(pDel == NULL)
	{
		cout<<"Danh sach rong, khong co ma xoa";
	}
	else
	{
		Node *pPre = NULL;
            while(pDel!= NULL)
		{
			if(pDel->info==d)
			{
				pPre=pDel;
				pDel=pDel->pNext;
                if(pDel == NULL)
		{
			cout<<"Khong thay"<<d<<" de xoa ";
		}
		else
		{
			if(pDel == list.pHead)
			{
				list.pHead= list.pHead->pNext;
				pDel->pNext == NULL;
				delete pDel;
				pDel = NULL;
			}
			else
			{
				pPre -> pNext = pDel ->pNext;
				pDel -> pNext = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
        }
			}
		}
	}

int main() {
    SingleList list;
    init(list);
    int n;
    cout <<"Nhap so Node: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int d;
        cout <<"Gia tri thu "<<i+1<<" cua Node la: ";
        cin >>d;
        InsertLast(list, d);
    }
    output(list);
    cout <<"\n So Node trong mang la: " << SizeOfList(list) <<endl;
    RemoveNode(list, 5);
    output(list);
    return 0;
}