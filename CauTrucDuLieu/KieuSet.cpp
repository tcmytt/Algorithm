#include<bits/stdc++.h>
using namespace std;

// Set la tap hop luu cac phan tu rieng biet. Thao tac deu la O(logn)
// Xay dung dua tren cay tim kiem nhi phan, luon sap xep theo thu tu tang dan
// Khong duyet dc bang index ma duyet bang interator

//De giam dan ta can tao struct cmp| LUU Y DE : a < b
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Giam dan
    }
};

int KieuSet(){
    set<int> s;
    s.insert(2);
    s.insert(1); // Them vao roi tu dong sap xep lai
    s.insert(1); // Khong them vao do 1 trung nhau

    int a[] = {1, 5, 2, 4, 3};
    set < int > soNguyen(a, a + 5); // integers = {1, 2, 3, 4, 5}.
    // Giam dan C1:
    auto cmp = [](int a, int b) {
        return a > b;  // So sánh ngược lại để tạo thứ tự giảm dần
    };    
    set < int , decltype(cmp) > GiamDan(cmp);
    // Giam dan C2: 
    set<int, Compare> mySet;

    auto DiaChi = s.find(1); // Tra ve interator phan tu do, khong co tra ve s.end();
    bool check = (s.end() != s.find(1)); // Tra ve 1 la tim thay, 0 la khong thay
    int tmp = s.count(2); // Tra ve so lan xuat hien cua khoa trong tap hop, 1 hoac 0
    s.lower_bound(1); // Tra ve interator phan tu nho nhat lon hon hoac bang key, ko thi s.end()
    s.upper_bound(1); // Tra ve interator phan tu nho nhat lon hon key,

    s.size(); // O(1)
    s.empty(); // O(1)
//  s.clear(); // O(n)
    soNguyen.erase(soNguyen.begin()); // Truyen vao interator hoac gia tri key


    for(int x : GiamDan){
        cout<<x<<" ";
    }
    return 0;
}


// Multiset giong set nhung luu duoc phan tu giong nhau
// Do phuc tap van logn
int KieuMultiset(){
    multiset<int> ms;
    ms.insert(100);
    ms.insert(100);
    ms.insert(100);

    // Luu y ham earse xoa het cac gia tri giong nhau,Xoa nen dung iterator
//    ms.erase(ms.find(a[i - k]));
    for(auto x : ms){
        cout<< x <<" ";
    }
    return 0;
}

int KieuUnordered_set(){
    unordered_set <int> us;
    //Thanh me no mang, do phuc tap O(n);
    return 0;
}

int main(){
    KieuMultiset();
    return 0;
}