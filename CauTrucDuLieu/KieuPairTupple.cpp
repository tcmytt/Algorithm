#include<bits/stdc++.h>
using namespace std;


int main(){
    pair<int,int> p1;
    pair<int,int> p2 = {100,200};
    pair<string,int> p3 = make_pair("Haaa", 200);

    p1.first;
    p1.second;

    tuple<int,int,int> t1{1,2,3};
    tuple<string,int,char,int> t2{1,2,3,4};
    get<0>(t1) ; //Lay gia tri dau tupple 1

    return 0;

}