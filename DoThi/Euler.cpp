#include<bits/stdc++.h>
using namespace std;

// Euler la ve moi canh, Halmiton la ve moi dinh
// Chu trinh Euler la chu trinh(Dinh bat dau va ket thuc la 1) di qua moi canh cua do thi dung 1 lan (Co the di qua dinh nhieu lan)
// Duong di euler la duong di moi canh do thi dung 1 lan

/* Dieu kien de do thi co chu trinh, duong di euler, 
// Do thi co chu trinh thi co duong di
Do thi vo huong : 
Chu trinh euler
    + Cac dinh bac khac 0 cua do thi lien thong voi nhau
    + Tat ca cac dinh cua do thi deu co bac chan
Duong di euler
    + Cac dinh bac khac 0 cua do thi lien thong voi nhau
    + Do thi co 0 hoac 2 dinh co bac le, trong TH 2 dinh bac le se bat dau va ket thuc o 2 dinh bac le nay

Do thi co huong :
Chu trinh euler
    + Cac dinh co bac khac 0 cua do thi thuoc cung 1 thanh phan lien thong
    + Moi dinh thuoc do thi deu co ban bac ra bang ban bac vao
Duong di euler 
    + Cac dinh co bac khac 0 cua do thi thuoc cung 1 thanh phan lien thong
    + Ton tai 2 dinh u,v ma : Ban bac ra u - Ban bac vao u = 1 && Ban bac vao v - Ban bac ra v =1 ; 
    moi dinh con lai deu co ban bac ra bang ban bac vao. Khi do duong di bat dau tu dinh u ket thuc dinh v
*/

int n,m;
// Dung set de xoa cho de
set<int> adj[1001];
// Mang luu bac
int degree[1001];

// Do thi vo huong, Chu trinh euler
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x,y; cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x] ++;
        degree[y] ++;
    }
}

//EU = Euler Cycle
void euler(int v){
    stack <int> st;
    vector <int> EC;
    st.push(v);
    while(st.empty() == false){
        int x= st.top();
        // Kiem tra neu van con dinh ke
        if(adj[x].size() != 0){
            // Lay ra dinh dau tien dua vao stack
            // st.push(*adj[x].begin());
            int y = *adj[x].begin();
            st.push(y);
            // Xoa canh x -> y ( = *adj[x].begin() );
            adj[x].erase(y);
            adj[y].erase(x);
        }else{
            st.pop();
            EC.push_back(x);
        }
    }
    // Lat nguoc hoac ko lat nguoc deu duoc
    reverse(begin(EC), end(EC));
    for(int x : EC) cout<< x << ' ';
}

int main(){
    inp();
    euler(1);
    return 0;
}

// 5 6 1 2 2 3 3 1 2 4 4 5 2 5

