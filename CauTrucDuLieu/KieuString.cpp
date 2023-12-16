#include<bits/stdc++.h>
using namespace std;

void KieuChar(){
    char KieuKiTu[30];
    cin.getline(KieuKiTu, 30);
}

void KienThuc(){
    // Truoc khi nhap getline ma co cin thi
    int n; cin >> n;
    cin.ignore();
    fflush(stdin);

    string s;
    cin >> s;
    getline(cin,s);

    s.size();
}

void TachTu(){
    string s = "java python php laptrinh";
    stringstream ss(s);
    string tmp;
    int cnt = 0;
    while(ss >> tmp){
        cout<<tmp <<endl;
        cnt++;
    }

    s = "java.python.php.laptrinh";
    //Tach theo dau cham
    while(getline(ss,tmp,'.')){
        cout<<tmp <<endl;
        cnt++;
    }    
}
int main(){
    string a = "python";
    string b = "java";
    string c = a + b; // Khong dung duoc dau -
//    a[0] = "9";  // Khong lam duoc nhu nay

//  a > b ; a < b; a == b; // So sanh theo thu tu tu dien
    a.compare(b); // a>b = 1; a=b =0 ; a<b = -1;
    string f = a.substr(2,4); // Cat tu vi tri 2 , 4 ki tu sau no
    a.substr(2); // CAt tu vi tri 2 den het
    

    string so = "154231564";
    int so1 = stoi(so);// Hoac stoll(so); doi voi so lon long long
    int n =154311563;
    so = to_string(n);

    for(int i = 0 ; i< a.size(); i++){
        cout<<a[i];
    }

    for(char x : a){
        cout<<x<<" ";
    }

    cout<<a;

    return 0;
}