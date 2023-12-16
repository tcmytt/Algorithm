// Cho 1 vector các string vector<string> words = {"ab","cd","ef"} .Hãy viết chương trình in ra tất cả các trường hợp khi kết hợp chúng lại
// VD: "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", và "efcdab" là tất cả các trường hợp thoả mãn 

#include <bits/stdc++.h>

using namespace std;

vector<string> ToHopTu;
bool check[10] ;

// Hàm lấy tổ hợp các trường hợp
void DeQuy(vector<string>& words, string ans, int count ,int i){
    int ws = words.size();
    if(count == ws ) {
        ToHopTu.push_back(ans);
        return;
    }

    for(int i =0; i<ws;i++){
        if(check[i] == false){
            check[i] = true;
            DeQuy(words,ans+words[i], count + 1 ,i);
            check[i] = false;
        }
    }
}

int main()
{
    vector<string> words = {"ab","cd","ef"};
    DeQuy(words,"",0,0);
    
    for(auto x : ToHopTu) cout<<x<<" ";

    return 0;
}





