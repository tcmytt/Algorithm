#include<bits/stdc++.h>
using namespace std;

// bitmask la xau nhi phan, mask la trang tha

// Tim bit thu i cua n 
bool bit(int n, int i){
    return (n>>i)&1;
    // Hoac #difine bit(n,i) ((n>>i)&1)
    // Kiem tra 2 bit co bang nhau va bang 1 khong ? co 4 trang thai bit nen j tu 0 -> 3
    for(int j=0;j<3;j++)
    if( bit(i,j) && bit (i,j+1) ) ... logic 
}



int main(){
    int n =1 << 3;
    cout<<bitset<10> a(n) <<endl;
    bitset<5> x('101111000111'); // Chi lay dc 5 bit dau do vuot qua va mang string phai toan 0 va 1
    bitset<10> c(20); // Nhi phan cua 20 phan thua o dau cho bang 0 het
    bitset<5> d('1011');

    // bitset giong nhu cai mang cua cac bit luu gia tri 0 va 1 ; khac voi bool can 1 bytes 8bit chi de luu true false 
    // Co the cout thang bitset ra khi khoi tao bat buoc la 1 so cu the bitset<10>(n) nhu day la 10
    // Khong chuyen qua lai duoc cho so am

    b[0] = 1; // Gán

    for(int i =0;i<d.size();i++){
        cout<<d[i];
        // bitset danh so tu phai qua nguoc lai khac mang
        // 1101
    }
    cout<<d; // 1011

	x.count(); // Dem so bit 1
    x.test(5); // test bit thu i co la 1 hay khong| Khong can in thang ra luon if(x[5]) luon 
    x.to_ulong();
    x.size(); //Kich thuoc khoi tao
    x.any();// Co 1 tra ve 1 ko co tra ve 0
    x.none();
    x.all();// tat ca bit co bang 1 hay khong
    x.flip(); //dao het
    
	//Tim loga co so 2 cua n=17;
    log2(n); // 4.xxx
    (int)log2(n);
    int tmp = 31 - __builtin_clz(n); // Nhanh hon cai tren

    int n = __builtin_popcountll(10);
    n = builtin_parityll(10);
    n =__builtin_clzll(10);
    n =__builtin_ctzll(10);
    n = __builtin_ffsll(10);

    d.to_ullong(); 
    d.to_string();
    d.to_ulong();

    cout<<__builtin_popcount(n);
    return 0;
}