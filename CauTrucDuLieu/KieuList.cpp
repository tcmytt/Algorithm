#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;
 
// Danh sach lien ket kep

int main()
{
    // defining list
    list<int> l{12,12,45,8,6};

    l.front();
    l.back();
    l.push_front(22);
    l.pop_front();
    l.push_back(33);
    l.pop_back();

    l.insert(l.begin(),5); // Chen dau
    l.size();
    
    l.remove(77); // xoa het phan tu 77

    // Xoa 1 phan tu
    l.erase(l.begin()); 

    // Xoa 1 khoang
    auto c = l.begin();
    advance(c,3); // Tang them 3 vi tri tu ban dau
    l.erase(l.begin(),c);
    
    for (auto i : l) {
        cout << i << ' ';
    }
    return 0;
}