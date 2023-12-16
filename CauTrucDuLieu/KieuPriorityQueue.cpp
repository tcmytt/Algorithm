#include<bits/stdc++.h>
using namespace std;

// Giong set, no cung duy tri thu tu sap xep, phan tu dau tien la lon nhat hoac nho nhat
// Khac set viec duy tri thu tu sau khi them moi nhanh hon set, cham hon trong lay ra
// O(nlogn) nhanh hon multiset ti

int KieuPQ(){
    //Mac dinh la max heap, max o dau
    priority_queue <int> pq;
    pq.push(100);
    pq.push(300);
    pq.push(200);
    //Phan tu o dau la 300 ( Lon Nhat )

    //Min heap
    priority_queue< int, vector<int>, greater<int> > rpq;
    //Top la min


    pq.pop(); // Xoa phan tu o dau
    pq.top(); // Phan tu o dau lon nhat
    pq.empty();
    pq.size();
    
}



int main(){


    return 0;
}