#include <forward_list>
#include <iostream>
using namespace std;

// Danh sach lien ket don

void KieuFL(){
    forward_list<int> f;
    f.assign({1,2,7,1,5,6,7,4,2,4});
    forward_list<int> f2;
    f2.assign(5,7); // 5 phan tu gia tri 7

    f.push_front(6); // Them vao dau
    f.emplace_front(6); // Giong tren nhung nhanh hon

    f.pop_front(); // Xoa dau
    f.insert_after(f.begin(), 11); // Chen vao sau vi tri dien vao, "Vi tri thu 2";
    f.insert_after(f.begin(),2, 22); // Chen 2 phan tu 22
//    f.erase_after(f.begin(), f.end()); // Xoa tu phan tu thu 2 den het; 
//    f.clear();

    f.remove(22); // Xoa het phan tu 22 trong dslk
    f.remove_if([](int x) { return x < 4; }); // Xoa voi dieu kien

    f.sort(); // Tang dan
    f.merge(f2); // Them vao truoc phan tu cuoi
    f.reverse(); // Lon duoi len dau
    f.unique(); // Xoa trung lap
    f.splice_after(f.begin(), f2, f2.begin(), f2.end()) ; // Khong hieu lam
    for (int& a : f)
        cout << a << " ";
    cout << endl;

    f.empty();

}

int main(){
    KieuFL();

    return 0;
}