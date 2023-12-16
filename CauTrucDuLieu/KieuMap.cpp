#include<bits/stdc++.h>
#include <map>
using namespace std;

// Map (dictionary) cai dat bang cay nhi phan tu can bang, hoac bang bam luu cap gia tri key - value
// Map tu dong sap xep theo khoa key (key - value) tang dan, moi phan tu cua map duoc cai dat theo kieu pair
// Key la rieng biet chi ton tai 1 key duy nhat, Chi co the duyet bang vong lap giong set
// O(logn)

int n = 10;
struct cmp
{
    bool operator() (char a, char b)
    {
        return a > b; // A > B
    }
};

void KieuMap(){
    map < string, int > m;
    map < int, int, cmp > rm; // Map giam dan
    m.insert({"bbbb", 20});
    m["aaaa"] = 10 ;
    m.insert({"cccc", 30});
    m["aaaa"] = 50 ;  // Ghi de vao thang {aaaa, 10}
    m.at("aaaa"); // giong m["aaaa"]

    // Cach duyet tuy bien
    // auto = map < string, int >::iterator
    for (auto it = m.begin(); it != m.end(); ++it)
        cout << (*it).first << ' ' << (*it).second << endl;

    // cac ham count find deu tim theo key, con lai giong set
    m.count("aaaa"); // Tra ve so lan xuat hien > 0 la tim thay
    auto tmp = m.find("aaaa") ; // Tra ve m.end() la khong tim thay

    m.erase("aaaa");
    

    //Truy cap den key chua ton tai trong map thi value cua no = 0; Dung de dam tan suat so lan xuat hien
    int a[1001];
    for(int i = 0 ; i< n ; i++){
        cin>>a[i];
        rm[a[i]]++; // ++ thanh 1, ban dau la 0
    }

    for(int i =0 ; i<n;i++){
        if(rm[a[i]] != 0 ){
            cout<<a[i]<< " "<< rm[a[i]] <<endl;
            rm[a[i]] = 0;
        }
    }    

    // Cach duyet toan bo map
    for(pair<string, int>  x : m){
//        cout<<x.first << " "<<x.second<<endl;
    }
}

void KieuMultimap (){
    //O(logn)
    multimap <int,int> m;
//  m[1] = 200; //Khong cho nhu nay duoc ma dung insert
    m.insert({1,200});
    m.insert({1,200});
    for(auto  x : m){
       cout<<x.first << " "<<x.second<<endl;
    }
    //Luu y giong Set khi xoa se xoa het key nen dung Xoa bang iterator
}

void Kieu_Unordered_Map(){
    // O(n);
    // Luu y khong luu duoc nhieu key giong nhau
    unordered_map<int,int> m;
    // Luu nhieu key giong nhau
    unordered_multimap<int,int> uomm;
}

int main(){
//    KieuMap();
    KieuMultimap();

    return 0;
}