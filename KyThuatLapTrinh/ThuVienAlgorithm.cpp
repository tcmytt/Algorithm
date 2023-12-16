#include <bits/stdc++.h>
#include<algorithm>
using namespace std;


int a[] = {9,2,7,4,8,5,1,5,4,6,3,7};
int n =sizeof(a) / sizeof(a[0]);
int b[12];
int d[50];
vector <int> c = {9,2,7,4,8,5,1,5,4,6,3,7} ;

// Chu y cac interator luon la a + x, a + y +1 de tinh tu x toi y, a+n tuong duong voi a.end()
// vector dung begin(a) va end(a) cho mang, string  hoac .begin() va .end() doi voi vector

bool cmp(int a , int b){
    return abs(a) < abs(b);
}

void Al(){
    min(10,220); 
    min({9,2,7,4,8,5,1,5,4,6,3,7}) ; //Nhieu so de vao {}
    min_element(a,a+n) ; // Tim min trong mang, vector, tra ve iter, vi tri = iter - a
    *min_element(a,a+n) ; // dua ve gia tri, 
    // min, max tuong tu

    int sum = accumulate(a, a+n, 0); // Tinh tong
    swap(a[1], a[2]); // Hoan doi

    sort(begin(a), end(a)); // Da hieu ro, mac dinh la tang dan
    sort(a, a+n, greater<int>()); // Giam dan them greater<int>()
    stable_sort(a,a+n,cmp);

    reverse(a, a+n); // Dao nguoc 
    reverse_copy(a,a+n,b); // Dao nguoc copy cua thang a va luu vao b; a khong bi dao nguoc
    
    count(a, a+12, 3); // Dem so lan xuat hien
    find(a, a+5, 3); // Tra ve con tro, khong thay tra ve thang sau thang cuoi(thang end), O(n)

    // Dung cho mang, vector da sap xep
    bool tmp = binary_search(a, a+5, 3); // ; Tra ve true, false
    lower_bound(a, a+5, 3); // Tra ve iter, ko co tra ve end, vi tri = iter - a, Tim >= x dau tien
    upper_bound(a, a+5, 3); // Tra ve iter, vi tri = iter - begin, Tim > x dau tien

    memset(a,0,sizeof(a)); // Chi gan mang tat ca thanh -1,0,1
    fill(a, a+n, 1000); // Gan tat ca voi gia tri 

    // Tron 2 mang, vector da sap xep
    vector <int> u = { 2 ,3 ,5 ,6 ,7};
    vector <int> v = { 1,3,4,9,10,12};
    vector <int> res(100) ; 
    // Luu y neu res ko cap phat bo nho truoc thi se khong merge duoc, tuy nhien se bi thua
    // Cach resize toi uu: 
    auto it = merge(u.begin(),u.end(), v.begin(), v.end(), res.begin()); // Tra ve iter cuoi
    res.resize(it - res.begin()) ;

    // Tap hop, truoc khi dung phai sort, deu tra ve iter cuoi de resize neu can
    it = set_union(a, end(a), b, end(b) , res.begin()) ; // Gan vao res phan tu 2 mang, trung nhau chi lay 1

    set_intersection(a, a+5, b, b+6 , d); // Gan vao d nhung phan giong nhau , trung nhau chi lay 1
    set_difference(a, a+5, b, b+6 , d); // Thuoc a khong thuoc b
    set_symmetric_difference(a, a+5, b, b+6 , d) ; // Khong lay nhung thang chung a b
    res.resize(it - res.begin()) ;
    for(int x : res){
        cout << x << " ";
    }
}

int main(){
    Al();
    return 0;
}