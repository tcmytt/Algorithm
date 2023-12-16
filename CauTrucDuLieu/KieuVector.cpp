#include<vector>
#include<bits/stdc++.h>
using namespace std;
// Vector la mang dong

int main(){
    int INF = 10000;
    int n = 10;
    // Tao vector
    vector<int> v;
    vector<int> u = { 1 ,2 , 3};
    // vector n phan tu
    vector<int> t(n);
    // vector d co 100 phan tu co gia tri 10000;
    vector<int> d(n+1 , INF);
    // vector luu chuoi
    vector<string> str;
    // vector luu vector
    vector< vector<int> > vec;
    // Min heap
    priority_queue< int, vector<int>, greater<int> > Q;
    // Gan
    int a[] = {1,2,3,4,5,6};
    v.assign(a, a+3); //1 2 3
    v.assign(7, 100); // Co 7 phan tu gia tri 100 

    str.push_back("chuoi 1");
    str.push_back("chuoi 2");
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.pop_back(); // Xoa cuoi

    v.size(); // Tra ve so phan tu hien co
    v.capacity(); // Tra ve dung luong mang duoc cap hien tai
    v.resize(n); // Chinh lai so size khong xoa phan tu thua
    v.shrink_to_fit(); // Xoa phan tu thua sau khi resize
    v.empty(); // Tra ve true | false
    v.erase(v.begin()); // Xoa phan tu dua vao iterator
    v.erase(v.begin(), v.begin() + 5); // Xoa 5 phan tu tu dau
    v.insert(v.begin()+2, 40); // Co the truyen vao 1 mang hay 1 vector cung kieu du lieu
    v.emplace(v.begin()+2, 40); // Emplace giong insert nhung nhanh hon
    v.emplace(v.end(), 70); // Chen vao cuoi
    v.clear(); // Xoa het

    v.at(0); // = v[0]
    v[0];
    v[v.size() - 1]; // Phan tu cuoi cung
    v.back(); // Phan tu cuoi cung
    v.front(); // Phan tu dau tien

    v.begin();  // Dia chi phan tu dau tien
    *v.begin(); // Gia tri phan tu dau tien
    v.end(); // Dia chi sau phan tu cuoi cung
    v.end() -1; // Dia chi phan tu cuoi cung
    *(v.end() -1) ; // Gia tri phan tu cuoi cung

    //Day gia tri vao vector
     for(int i =0 ;i < n; i++){
        int x; cin>>x;
        t.push_back(x);
    }   

    // Duyet qua index
    for(int i =0 ;i < v.size(); i++){
        v[i];
    }

    // Khong thay doi duoc gia tri
    for( int x : v ){
        x;
    }
    // Thay doi duoc gia tri
    for( int &x : v ){
        x += 5;
    }


    //Tach string luu vao vector
    string s = " day la 1 dong vo nghia" ;
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        str.push_back(tmp);
    }
    return 0;
}